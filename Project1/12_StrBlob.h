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

//前置声明
class StrBlobPtr;
class StrBlob {
public:
	//友元声明
	friend class StrBlobPtr;
	typedef vector<string>::size_type size_type;

	StrBlob();	
	//加了explicit就不能用列表初始化了:StrBlob b1 = {...}
	//explicit StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
	StrBlob(initializer_list<string> il);

	size_type size() const;
	bool empty() const;

	void push_back(const string &s);
	void pop_back();

	string& front();
	string& back();

	//const方法在返回值前和参数列表后都要加const
	const string& front() const;
	const string& back() const;
	//非常量迭代器
	StrBlobPtr begin();
	StrBlobPtr end();

	//常量迭代器
	const StrBlobPtr begin() const;
	const StrBlobPtr end() const;
	const StrBlobPtr cbegin() const;
	const StrBlobPtr cend() const;

private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const {
		if (i < 0 || i >= size()) {
			throw out_of_range(msg);
		}
	}
};
