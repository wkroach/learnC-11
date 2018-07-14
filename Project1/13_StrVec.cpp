#include"13_StrVec.h"

//重载相等，不等运算符
bool operator == (const StrVec &lhs, const StrVec &rhs) {
	auto p1 = lhs.begin(), p2 = rhs.begin();
	for (; p1 != lhs.end() && p2 != rhs.end(); ++p1, ++p2) {
		if (*p1 != *p2) {
			return false;
		}
	}
	return p1 == lhs.end() && p2 == rhs.end();
}
bool operator != (const StrVec &lhs, const StrVec &rhs) {
	return !(lhs == rhs);
}

std::allocator<std::string> StrVec::alloc;
//默认构造函数
StrVec::StrVec():element(nullptr), first_free(nullptr), cap(nullptr){
}

StrVec::StrVec(std::initializer_list<std::string> il){
	auto data = alloc_n_copy(il.begin(), il.end());
	element = data.first;
	first_free = cap = data.second;
}

//拷贝构造
StrVec::StrVec(const StrVec &rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	element = data.first;
	first_free = cap = data.second;
}

//赋值构造
StrVec &StrVec::operator=(const StrVec &rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	element = data.first;
	first_free = cap = data.second;
	return *this;
}

StrVec::~StrVec(){
	free();
	std::cout << "free success" << std::endl;
}

void StrVec::push_back(const std::string &str){
	//确保有空间构造新元素，否则新开辟内存
	check_n_alloc();
	alloc.construct(first_free++, str);
}

//为StrVec新分配至少为newCapacity大小的新内存
void StrVec::reserve(size_t newCapacity){
	if (newCapacity <= capacity()) {
		return;
	}
	reallocate(std::max(newCapacity, size() * 2));
}

//当newSize大于capacity时，直接reallocate，大于size时，直接往后添加默认元素，小于size时，从后往前删释放内存
void StrVec::resize(size_t newSize) {
	resize(newSize, "");
}

void StrVec::resize(size_t newSize, const std::string &newValue){
	if (newSize > capacity()) {
		reallocate(std::max(newSize, size() * 2));
	}
	if (newSize > size()) {
		for (int i = size(); i < newSize; ++i) {
			alloc.construct(first_free++, newValue);
		}
	}
	else {
		for (int i = size(); i > newSize; --i) {
			alloc.destroy(--first_free);
		}
	}
}

//将已有内存里的元素拷贝至新分配的内存中
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *begin, const std::string *end){
	auto data = alloc.allocate(end - begin);
	return{ data, std::uninitialized_copy(begin, end, data) };
}

//释放已分配内存,要按照初始化顺序从后往前释放
void StrVec::free(){
	if (element != nullptr) {
		for (auto it = first_free; it != element; ) {
			alloc.destroy(--it);
		}
		alloc.deallocate(element, cap - element);
		element = first_free = cap = nullptr;
	}
}

//检查是否有多余已分配内存来添加新的元素，如果没有就重新分配内存
void StrVec::check_n_alloc(){
	if (size() == capacity()) {
		reallocate();
	}
}

//!!!!最重要
//为StrVec重新分配内存，并将原有元素拷贝/移动至新内存，然后删除原有内存
void StrVec::reallocate(){
	auto newCapacity = size() ? size() * 2 : 1;
	reallocate(newCapacity);
}

void StrVec::reallocate(size_t newCapacity){
	auto newElement = alloc.allocate(newCapacity);
	auto newFirstFree = newElement;
	auto toDelete = element;
	for (int i = 0; i < size(); ++i) {
		alloc.construct(newFirstFree++, std::move(*toDelete++));
	}
	free();
	element = newElement;
	first_free = newFirstFree;
	cap = element + newCapacity;
}
