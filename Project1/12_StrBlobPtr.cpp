#include"12_StrBlobPtr.h"
#include"12_StrBlob.h"

bool operator == (const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return lhs.get_data_address() == rhs.get_data_address() &&
		lhs.get_cur() == rhs.get_cur();
		   
}
bool operator != (const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
	return !(lhs == rhs);
}

StrBlobPtr::StrBlobPtr() :cur(0) {}
StrBlobPtr::	StrBlobPtr(StrBlob& strBlob, size_type pos = 0) :wptr(strBlob.data), cur(pos) {}
StrBlobPtr::	StrBlobPtr(const StrBlob &strBlob, size_type pos = 0) :wptr(strBlob.data), cur(pos) {}

StrBlobPtr& StrBlobPtr::next() {
		check();
		cur++;
		return *this;
	}
const StrBlobPtr& StrBlobPtr::next() const {
	check();
	cur++;
	return *this;
}
string& StrBlobPtr::refer(){
		return check()->at(cur);
	}
const string& StrBlobPtr::refer() const {
	return check()->at(cur);
}
shared_ptr<vector<string>> StrBlobPtr::check() const{
		auto ptr = wptr.lock();
		if (ptr == nullptr) {
			throw runtime_error("wptr is empty");
		}
		if(cur <0 || cur >= ptr->size()){
			throw out_of_range("cur is out of range");
		}
		return ptr;
	}
