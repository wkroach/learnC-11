#include"12_StrBlob.h"
#include"12_StrBlobPtr.h"

bool operator == (const StrBlob &lhs, const StrBlob &rhs) {
	return	lhs.get_data() == rhs.get_data();
}

bool operator != (const StrBlob &lhs, const StrBlob &rhs) {
	return !(lhs == rhs);
}

StrBlob::StrBlob():data(make_shared<vector<string>>()){}
	//加了explicit就不能用列表初始化了:StrBlob b1 = {...}
	//explicit StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
StrBlob::StrBlob(initializer_list<string> il) :data(make_shared<vector<string>>(il)) {}
StrBlob::size_type StrBlob::size() const {
		return data->size();
	}
bool StrBlob::empty() const {
		return data->empty();
	}
void StrBlob::push_back(const string &s) {
		data->push_back(s);
	}
void StrBlob::pop_back() {
		data->pop_back();
	}
string& StrBlob::front() {
		return data->front();
	}
string& StrBlob::back()  {
		return data->front();
	}
	//const方法在返回值前和参数列表后都要加const
const string& StrBlob::front() const{
		return data->front();
	}
const string& StrBlob::back() const {
		return data->back();
	}
StrBlobPtr StrBlob::begin() {
		return StrBlobPtr(*this, 0);
	}
StrBlobPtr StrBlob::end() {
		return StrBlobPtr(*this, data->size());
	}

const StrBlobPtr StrBlob::begin() const{
	return StrBlobPtr(*this, 0);
}

const StrBlobPtr StrBlob::end() const{
	return StrBlobPtr(*this, data->size());
}

const StrBlobPtr StrBlob::cbegin() const
{
	return StrBlobPtr(*this, 0);
}

const StrBlobPtr StrBlob::cend() const
{
	return StrBlobPtr(*this, data->size());
}
