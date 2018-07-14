#pragma once

#include<iostream>
#include<vector>
#include<numeric>
#include<list>
#include<forward_list>
#include<deque>
#include<string>
#include<iterator>
#include<functional>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<utility>
#include<memory>
#include<algorithm>
using namespace std;

//由于两个类互相使用,所以在声明时都应该用前置声明另一个类
class StrBlob;
class StrBlobPtr {
public:
	friend bool operator == (const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator != (const StrBlobPtr&, const StrBlobPtr&);

	typedef vector<string>::size_type size_type;

	StrBlobPtr();
	StrBlobPtr(StrBlob &strBlob, size_type pos);
	StrBlobPtr(const StrBlob &strBlob, size_type pos);

	//返回week_ptr指向vector<string>对象的地址
	const vector<string>* get_data_address() const{
		return &(*wptr.lock());
	}
	size_type get_cur() const {
		return cur;
	}

	StrBlobPtr& next();
	//常量next，这样StrBlobPtr依旧可以迭代
	const StrBlobPtr& next() const;
	string& refer();
	const string& refer() const;
	shared_ptr<vector<string>> check() const;
private:
	//将cur设置为mutable，这样常量StrBlobPtr依旧可以迭代
	mutable size_type cur;
	weak_ptr<vector<string>> wptr;
};

