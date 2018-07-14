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

//ǰ������
class StrBlobPtr;
class StrBlob {
public:
	//��Ԫ����
	friend class StrBlobPtr;
	friend bool operator == (const StrBlob&, const StrBlob&);
	friend bool operator != (const StrBlob&, const StrBlob&);
	typedef vector<string>::size_type size_type;

	StrBlob();	
	//����explicit�Ͳ������б��ʼ����:StrBlob b1 = {...}
	//explicit StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
	StrBlob(initializer_list<string> il);

	size_type size() const;
	bool empty() const;

	//shared_ptr�޷���const ָ��һ�����û��޷�ͨ��ָ���޸Ķ���
	//��data��ָ�����ĵ�ַ��constָ�뷵�أ����޷�ͨ���˵�ַ����dataָ��Ķ�������޸�
	const vector<string>* get_data() const {
		return &(*data);
	}

	void push_back(const string &s);
	void pop_back();

	string& front();
	string& back();

	//const�����ڷ���ֵǰ�Ͳ����б��Ҫ��const
	const string& front() const;
	const string& back() const;
	//�ǳ���������
	StrBlobPtr begin();
	StrBlobPtr end();

	//����������
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
