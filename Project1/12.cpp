#include"12.h"


void Problem12_1() {
	StrBlob b1;
	{
		StrBlob b2 = { "I", "want", "AD", "from", "CMU" };
		b1 = b2;
		b2.push_back("and UCSD");
		cout << "b2 size"<<" "<<b2.size() << endl;
	}
	cout << "b1 size" << " " << b1.size() << endl;
}

void Problem12_2() {
	StrBlob b1 = { "I", "want", "AD", "from", "CMU", "and", "UCSD" };
	const StrBlob b2 = b1;
	b1.front() = "Ke Wu";
	cout << b1.front() << endl;
	//b2.front() = "Wu Ke";
	cout << b2.front() << endl;
}

void _Problem12_10(shared_ptr<int> ptr) {
	cout << "in process" << " " << ptr.use_count() << endl;
}

void Problem12_10() {
	shared_ptr<int> ptr = make_shared<int>(42);
	_Problem12_10(ptr);
	cout << "out process" << " " << ptr.use_count() << endl;
}

//C++11中严禁用智能指针的get()方法初始化另外的智能指针
void Problem12_11() {
	shared_ptr<int> ptr = make_shared<int>(42);
	_Problem12_10(shared_ptr<int>(ptr.get()));
	cout << ptr.use_count() << endl;
}

//不能用普通指针赋值智能指针
//只能用普通指针初始化智能指针
void Problem12_12() {
	auto p = new int();
	auto sp = make_shared<int>();
	_Problem12_10(sp);
	//!sp = p;
	//!shared_ptr<int> pt = new int();
	//!shared_ptr<int> pt = p;
	//!_Problem12_10(new int());
	//!_Problem12_10(p);
	_Problem12_10(shared_ptr<int>(p));
}

//禁止delete智能指针get()得到的指针
void Problem12_13() {
	auto sp = make_shared<int>();
	auto p = sp.get();
	delete p;
}

//对于不是new出来的对象,不能用delete释放
//这种情况要在初始化智能指针时,使用一个以对象指针为参数的可调用函数
void Problem12_14() {
	int i = 0;
	//!shared_ptr<int> pt(&i);
	shared_ptr<int> pt(&i, [](int *p) {return; });
}

//unique_ptr不支持赋值和拷贝
void Problem12_16() {
	unique_ptr<int> pt(new int(0));
	unique_ptr<int> pt2;
	//pt2 = pt;
}

//不能用不是new出来的对象地址初始化unique_ptr
//更不能用智能指针的get()初始化unique_ptr
void Problem12_17() {
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	typedef unique_ptr<int> IntP;
	//!IntP p0(ix);
	//!IntP p1(pi);
	IntP p2(pi2);
	//!IntP p3(&ix);
	IntP p4(new int(2048));
	//!IntP p5(p2.get());
}


void Problem12_20() {
	vector<string>arr = { "I", "want", "AD", "from", "UIUC" };
	StrBlob strBlob;
	for (auto &item : arr) {
		strBlob.push_back(item);
	}
	StrBlobPtr strBlobPtr = strBlob.begin();
	try {
		while (strBlobPtr.check()) {
			cout << strBlobPtr.refer() << " ";
			strBlobPtr.next();
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
	try {
		strBlobPtr = strBlob.begin();
		while (strBlobPtr.check()) {
			strBlobPtr.refer() = "1";
			cout << strBlobPtr.refer() << " ";
			strBlobPtr.next();
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}
}

void Problem12_22() {
	vector<string>arr = { "I", "want", "AD", "from", "UIUC" };
	const StrBlob cstrBlob;
	StrBlob strBlob;
	for (auto &s : arr) {
		strBlob.push_back(s);
	}
	const StrBlobPtr strBlobPtr = cstrBlob.begin();
	try {
		while (strBlobPtr.check()) {
			cout << strBlobPtr.refer() << " ";
			strBlobPtr.next();
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

	try {
		const StrBlobPtr cstrBlobPtr = strBlob.cbegin();
		while (cstrBlobPtr.check()) {
			cout << cstrBlobPtr.refer() << " ";
			cstrBlobPtr.next();
		}
	}
	catch (exception e) {
		cout << e.what() << endl;
	}

}

char* _Problem12_23(char *str1, char *str2) {
	char *strAns = new char[strlen(str1) + strlen(str2) + 1];
	int i;
	for (i = 0; i < strlen(str1); ++i) {
		strAns[i] = str1[i];
	}
	int j;
	for (j = 0; j < strlen(str2); ++j) {
		strAns[i + j] = str2[j];
	}
	strAns[i+j] = '\0';
	return strAns;
}
void Problem12_23() {
	char *str1 = "I want AD from CMU";
	char *str2 = " and UIUC and UCSD";
	char *str = _Problem12_23(str1, str2);
	cout << str << endl;
	delete[] str;
}

void Problem12_26() {
	vector<string> arr = { "I", "want", "AD", "from", "UIUC", "and", "CMU", "and", "UCSD" };
	allocator<string> alloc;
	auto p = alloc.allocate(10);
	auto q = p;
	for (int i = 0; i < arr.size() && q != p + 10;++i) {
		alloc.construct(q++, arr[i]);
	}
	auto q2 = p;
	for (; q2 != q;) {
		cout << *q2++ << " ";
	}
	cout << endl;
	while (q != p) {
		alloc.destroy(--q);
	}
	alloc.deallocate(p, 10);
}