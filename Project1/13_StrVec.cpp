#include"13_StrVec.h"

//������ȣ����������
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
//Ĭ�Ϲ��캯��
StrVec::StrVec():element(nullptr), first_free(nullptr), cap(nullptr){
}

StrVec::StrVec(std::initializer_list<std::string> il){
	auto data = alloc_n_copy(il.begin(), il.end());
	element = data.first;
	first_free = cap = data.second;
}

//��������
StrVec::StrVec(const StrVec &rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	element = data.first;
	first_free = cap = data.second;
}

//��ֵ����
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
	//ȷ���пռ乹����Ԫ�أ������¿����ڴ�
	check_n_alloc();
	alloc.construct(first_free++, str);
}

//ΪStrVec�·�������ΪnewCapacity��С�����ڴ�
void StrVec::reserve(size_t newCapacity){
	if (newCapacity <= capacity()) {
		return;
	}
	reallocate(std::max(newCapacity, size() * 2));
}

//��newSize����capacityʱ��ֱ��reallocate������sizeʱ��ֱ���������Ĭ��Ԫ�أ�С��sizeʱ���Ӻ���ǰɾ�ͷ��ڴ�
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

//�������ڴ����Ԫ�ؿ������·�����ڴ���
std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *begin, const std::string *end){
	auto data = alloc.allocate(end - begin);
	return{ data, std::uninitialized_copy(begin, end, data) };
}

//�ͷ��ѷ����ڴ�,Ҫ���ճ�ʼ��˳��Ӻ���ǰ�ͷ�
void StrVec::free(){
	if (element != nullptr) {
		for (auto it = first_free; it != element; ) {
			alloc.destroy(--it);
		}
		alloc.deallocate(element, cap - element);
		element = first_free = cap = nullptr;
	}
}

//����Ƿ��ж����ѷ����ڴ�������µ�Ԫ�أ����û�о����·����ڴ�
void StrVec::check_n_alloc(){
	if (size() == capacity()) {
		reallocate();
	}
}

//!!!!����Ҫ
//ΪStrVec���·����ڴ棬����ԭ��Ԫ�ؿ���/�ƶ������ڴ棬Ȼ��ɾ��ԭ���ڴ�
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
