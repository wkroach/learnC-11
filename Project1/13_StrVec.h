#pragma once
#include<string>
#include<memory>
#include<utility>
#include<vector>
#include<algorithm>

class StrVec {
public:
	StrVec();
	StrVec(std::initializer_list<std::string> il);
	StrVec(const StrVec&);
	StrVec& operator=(const StrVec&);
	~StrVec();

	void push_back(const std::string&);
	std::string *begin() const {
		return element;
	}
	std::string *end() const {
		return first_free;
	}
	size_t size() const {
		return first_free - element;
	}
	size_t capacity() const {
		return cap - element;
	}
	void reserve(size_t newCapacity);
	void resize(size_t newSize, const std::string &newValue = "");


private:
	static std::allocator<std::string> alloc;

	std::string *element;
	std::string *first_free;
	std::string *cap;

	std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
	void free();
	void check_n_alloc();

	void reallocate();
	void reallocate(size_t newCapacity);
};
