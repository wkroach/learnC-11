#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory>

#include"13_StrVec.h"
#include"13_String.h"
using namespace std;

class A {
public:
	string str;
	A() {
		cout << "A()" << endl;
	}
	/*
		此处会有从string到A：的隐式类型转换
		使得 A a = str; a = str; 这样的赋值运算成立
	*/
	A(const string& str) {
		this->str = str;
		cout << "A(const string&)" << endl;
	}
	A(const char* str) {
		cout << "A(const char*)" << endl;
	}
	
	A& operator=(const A&) {
		cout << "A=(const A&)" << endl;
		return *this;
	}
	
//private:
	/*
		拷贝构造函数必须为public
	*/
	A(const A& a):str(a.str){
		cout << "copy reference" << endl;
	}
};

class numbered {
public:
	int mysn;
	static int count;
	numbered() {
		mysn = count++;
	}
	//此类结构可以根据3.14, 3.15, 3.16, 3.17中的要求调整
	numbered(const numbered& rhs) {
		mysn = count++;
	}
};


class HasPtr {
public:
	friend void swap(HasPtr &lhs, HasPtr &rhs);
	HasPtr(const string &s = string()) :ps(new string(s)), i(0) {}
	HasPtr(const HasPtr& hasPtr) :ps(new string(*hasPtr.ps)),i(hasPtr.i) {
		cout << "copy constructor" << endl;
	}
	//HasPtr& operator=(const HasPtr& hasPtr) {
	//	string tmpStr = *hasPtr.ps;
	//	delete ps;
	//	ps = new string(tmpStr);
	//	i = hasPtr.i;
	//	cout << "copy assignment" << endl;
	//	return *this;
	//}

	//operator=(HasPtr)不能与operator=(HasPtr&&)共存，对于右值实参两者具有相同的参数匹配优先级
	//当定义了移动构造函数时，一个operator=(HasPtr)即可满足移动和赋值两种功能(形参构造时实现，与swap无关)
	HasPtr& operator=(HasPtr rhs) {
		swap(*this, rhs);
		cout << "copy and swap assignment" << endl;
		return *this;
	}
	HasPtr(HasPtr&& rhs) :ps(rhs.ps), i(rhs.i) { 
		rhs.ps = nullptr; 
		cout << "move constructor" << endl;
	}
	//HasPtr& operator=(HasPtr&& rhs) {
	//	ps = rhs.ps;
	//	i = rhs.i;
	//	rhs.ps = nullptr;
	//	cout << "move assignment" << endl;
	//	return *this;
	//}
	bool operator < (const HasPtr& rhs) {
		cout << "<" << endl;
		return *ps < *rhs.ps;
	}
	~HasPtr() {
		delete ps;
	}
	string getString() const{
		return *ps;
	}
private:
	string *ps;
	int i;
};
inline void swap(HasPtr &lhs, HasPtr &rhs) {
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
	cout << "HasPtr: swap" << endl;
}

class HasPtrRef {
public:
	HasPtrRef(const string &str = ""): ps(new string(str)), i(0), puse(new int(0)) {}
	HasPtrRef(const HasPtrRef &rhs): ps(rhs.ps), i(rhs.i), puse(rhs.puse) { ++*puse; }
	HasPtrRef& operator = (const HasPtrRef &rhs) {
		++*rhs.puse;
		if (--*puse == 0) {
			delete ps;
			delete puse;
		}
		ps = rhs.ps;
		puse = rhs.puse;
		return *this;
	}
	~HasPtrRef() {
		if (--*puse == 0) {
			delete ps;
			delete puse;
		}
	}
private:
	string *ps;
	int *puse;
	int i;
};

void Problem13_1();
void Problem13_4();
void Problem13_5();
void Problem13_8();
void Problem13_14();
void Problem13_15();
void Problem13_16();
void Problem13_30();
void Problem13_31();
void Problem13_testStrVec();
void Problem13_44();
void Problem13_46();
void Problem13_48();
void Problem13_50();
void Problem13_53();