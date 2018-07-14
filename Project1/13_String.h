#pragma once
#include<iostream>
#include<cstring>
#include<memory>
#include<utility>
#include<algorithm>

//声明与实现与StrVec基本一致,
class String {
public:
	friend std::ostream& operator <<(std::ostream &os, const String&);
	friend bool operator == (const String&, const String&);
	friend bool operator != (const String&, const String&);

	String();
	String(const char*);
	String(const String &);
	String& operator=(const String &);
	String(String &&);
	String& operator=(String &&);
	~String();
	void push_back(const char&);
	char *begin() const {
		return first_element_;
	};
	char *end() const {
		return first_free_;
	};
	size_t size() const {
		return first_free_ - first_element_;
	};
	size_t capacity() const {
		return capacity_ - first_element_;
	};
	void resize(size_t);
	void resize(size_t, const char&);
private:
	static std::allocator<char> alloc_;
	char *first_element_;
	char *first_free_;
	char *capacity_;

	std::pair<char*, char*> alloc_copy(const char *begin, const char *end);
	void free();
	void check_alloc();

	void reallocate();
	void reallocate(size_t new_capacity);
};
