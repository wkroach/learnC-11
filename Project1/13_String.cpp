#include"13_String.h"

bool operator == (const String &lhs, const String &rhs) {
	auto p1 = lhs.begin(), p2 = rhs.begin();
	for (; p1 != lhs.end() && p2 != rhs.end(); ++p1, ++p2) {
		if (*p1 != *p2) {
			return false;
		}
	}
	return p1 == lhs.end() && p2 == rhs.end();
}
bool operator != (const String &lhs, const String &rhs) {
	return !(lhs == rhs);
}

std::allocator<char> String::alloc_;

std::ostream& operator<<(std::ostream &os, const String &rhs) {
	std::cout << "using operator << for String: " << std::endl;
	for (auto it = std::begin(rhs); it != std::end(rhs); ++it) {
		os << *it;
	}
	return os;
}

//默认构造函数
String::String():first_element_(nullptr), first_free_(nullptr), capacity_(nullptr){
}

String::String(const char *str){
	auto begin = str;
	auto end = begin + strlen(str);
	auto data = alloc_copy(begin, end);
	first_element_ = data.first;
	first_free_ = capacity_ = data.second;
	std::cout << "const char* constructor" << std::endl;
}

String::String(const String &rhs){
	auto data = alloc_copy(std::begin(rhs), std::end(rhs));
	first_element_ = data.first;
	first_free_ = capacity_ = data.second;
	std::cout << "copy constructor" << std::endl;
}

String &String::operator=(const String &rhs){
	auto data = alloc_copy(std::begin(rhs), std::end(rhs));
	free();
	first_element_ = data.first;
	first_free_ = capacity_ = data.second;
	std::cout << "copy assignment" << std::endl;
	return *this;
}

String::String(String &&rhs):first_element_(rhs.first_element_),
							 first_free_(rhs.first_free_),
							 capacity_(rhs.capacity_){
	rhs.first_element_ = rhs.first_free_ = rhs.capacity_ = nullptr;
	std::cout << "move constructor" << std::endl;
}

String & String::operator=(String &&rhs){
	free();
	first_element_ = rhs.first_element_;
	first_free_ = rhs.first_free_;
	capacity_ = rhs.capacity_;
	rhs.first_element_ = rhs.first_free_ = rhs.capacity_ = nullptr;
	std::cout << "move assignment" << std::endl;
	return *this;
}

String::~String(){
	free();
	//std::cout << "free success" << std::endl;
}

void String::push_back(const char &ch){
	check_alloc();
	alloc_.construct(first_free_++, ch);
}

void String::resize(size_t new_size){
	resize(new_size, '\0');
}

void String::resize(size_t new_size, const char &ch){
	if (new_size > capacity()) {
		reallocate(std::max(new_size, 2 * size()));
	}
	if (new_size > size()) {
		for (int i = size(); i < new_size; ++i) {
			alloc_.construct(first_free_++, ch);
		}
	}
	else {
		for (int i = size(); i > new_size; --i) {
			alloc_.destroy(--first_free_);
		}
	}
}

std::pair<char*, char*> String::alloc_copy(const char * begin, const char * end){
	auto first_element = alloc_.allocate(end - begin);
	return{first_element, std::uninitialized_copy(begin, end, first_element)};
}

void String::free(){
	if (first_element_ != nullptr) {
		for (auto p = first_free_; p != first_element_; ) {
			alloc_.destroy(--p);
		}
		alloc_.deallocate(first_element_, capacity_ - first_element_);
		first_element_ = first_free_ = capacity_ = nullptr;
	}
}

void String::check_alloc(){
	//当size和capacity相等时才需要扩容
	//此写法包括了三个指针均为nullptr的情况
	if (size() == capacity()) {
		reallocate();
	}
}

void String::reallocate(){
	size_t new_capacity = size() != 0 ? 2 * size() : 1;
	reallocate(new_capacity);
}

void String::reallocate(size_t new_capacity){
	auto new_first_element = alloc_.allocate(new_capacity);
	auto new_first_free = new_first_element;
	for (auto p = first_element_; p != first_free_; ) {
		alloc_.construct(new_first_free++, std::move(*p++));
	}
	free();
	first_element_ = new_first_element;
	first_free_ = new_first_free;
	capacity_ = first_element_ + new_capacity;
}
