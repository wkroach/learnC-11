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

//���������໥��ʹ��,����������ʱ��Ӧ����ǰ��������һ����
class StrBlob;
class StrBlobPtr {
public:
	friend bool operator == (const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator != (const StrBlobPtr&, const StrBlobPtr&);

	typedef vector<string>::size_type size_type;

	StrBlobPtr();
	StrBlobPtr(StrBlob &strBlob, size_type pos);
	StrBlobPtr(const StrBlob &strBlob, size_type pos);

	//����week_ptrָ��vector<string>����ĵ�ַ
	const vector<string>* get_data_address() const{
		return &(*wptr.lock());
	}
	size_type get_cur() const {
		return cur;
	}

	StrBlobPtr& next();
	//����next������StrBlobPtr���ɿ��Ե���
	const StrBlobPtr& next() const;
	string& refer();
	const string& refer() const;
	shared_ptr<vector<string>> check() const;
private:
	//��cur����Ϊmutable����������StrBlobPtr���ɿ��Ե���
	mutable size_type cur;
	weak_ptr<vector<string>> wptr;
};

