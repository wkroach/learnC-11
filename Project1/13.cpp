#include "13.h"

void Problem13_1() {
	string str = "123";
	A a = "123";
	A c = str;
	//使用了拷贝赋值函数，且由于构造函数存在，产生str到A的隐式转：换
	c = str;
	A b;
	//非初始化时的赋值，使用(合成)拷贝赋值函数
	b = a;
	//初始化时的赋值和直接初始化，均使用(合成的)拷贝构造函数，且如定义了就必须为public
	A aa(b);
	A aaa = b;
}

A foo_bar(A arg) {
	/*
	拷贝构造存在于形参初始化，变量初始化，new / shared_ptr初始化，函数返回值初始化
	*/
	A global;
	A local = arg;
	shared_ptr<A> heap = make_shared<A>(global);
	*heap = local;
	A arr[4] = { local, *heap };
	return *heap;
}

void Problem13_4() {
	A a;
	foo_bar(a);
}

void Problem13_5() {
	HasPtr hasPtr("123");
	HasPtr hasPtr2 = hasPtr;
	cout << hasPtr.getString() << endl;
	cout << hasPtr2.getString() << endl;
}

void Problem13_8() {
	HasPtr hasPtr("123");
	HasPtr hasPtr2("456");
	hasPtr2 = hasPtr;
	cout << hasPtr.getString() << endl;
	cout << hasPtr2.getString() << endl;
	hasPtr2 = hasPtr2;
	cout << hasPtr2.getString() << endl;
}

int numbered::count = 0;
void _Problem13_14(numbered s) {
	cout << s.mysn << endl;
}
void _Problem13_16(const numbered& s) {
	cout << s.mysn << endl;
}
void Problem13_14() {
	//记得将numbered中的拷贝构造函数注释掉
	numbered a, b = a, c = b;
	_Problem13_14(a);
	_Problem13_14(b);
	_Problem13_14(c);
}
void Problem13_15() {
	numbered a, b = a, c = b;
	_Problem13_14(a);
	_Problem13_14(b);
	_Problem13_14(c);
	cout << a.mysn << endl;
	cout << b.mysn << endl;
	cout << c.mysn << endl;
}
void Problem13_16() {
	numbered a, b = a, c = b;
	_Problem13_16(a);
	_Problem13_16(b);
	_Problem13_16(c);
	cout << a.mysn << endl;
	cout << b.mysn << endl;
	cout << c.mysn << endl;
}

void Problem13_30() {
	HasPtr hasPtr("123");
	HasPtr hasPtr2("456");
	swap(hasPtr, hasPtr2);
	cout << hasPtr.getString() << endl;
	cout << hasPtr2.getString() << endl;
}

void Problem13_31() {
	vector<HasPtr> arr = { HasPtr("123"), HasPtr("321"), HasPtr("121") };
	sort(begin(arr), end(arr));
	for (auto &hasPtr : arr) {
		cout << hasPtr.getString() << " ";
	}
	cout << endl;
}

void Problem13_testStrVec() {
	auto loop = [](const string &str){
		cout << str << " ";
	};
	//构造
	StrVec strVec = { "123", "456", "789" };
	for_each(begin(strVec), end(strVec), loop);
	cout << endl;
	//拷贝构造
	StrVec strVec2(strVec);
	for_each(begin(strVec2), end(strVec2), loop);	
	cout << endl;
	//push_back
	strVec2.push_back("101112");
	for_each(begin(strVec2), end(strVec2), loop);
	cout << endl;
	//赋值构造
	StrVec strVec3;
	strVec3 = strVec2;
	for_each(begin(strVec3), end(strVec3), loop);
	cout << endl;
	//自赋值
	strVec = strVec;
	for_each(begin(strVec), end(strVec), loop);
	cout << endl;
	//resize
	strVec2.resize(1);
	cout << strVec2.size() << " " << strVec2.capacity() << endl;
	for_each(begin(strVec2), end(strVec2), loop);
	cout << endl;
	//reserve
	strVec3.reserve(5);
	cout << "strVec3: " << strVec3.size() << " " << strVec3.capacity() << endl;
	cout << endl;
	strVec3 = strVec;
	strVec3.reserve(10);
	cout << "strVec3: " << strVec3.size() << " " << strVec3.capacity() << endl;
	cout << endl;
	//reallocate
	StrVec strVec4;
	for (int i = 0; i < 100; ++i) {
		cout << strVec4.size() << " " << strVec4.capacity() << endl;
		strVec4.push_back("hehe");
	}
}

void Problem13_44() {
	String str1 = "123";
	cout<<str1<<endl;
	String str2 = str1;
	str2.push_back('4');
	cout << str2 << endl;
	String str3;
	str3 = str2;
	cout << str3 << endl;
	str1 = str1;
	cout << str1 << endl;
	for (int i = 0; i < 100; ++i) {
		cout << str1.size() << " " << str1.capacity() << endl;
		str1.push_back('c');
	}
}

void Problem13_46() {
	auto f = []() {return 1; };
	vector<int> vi(100);
	int &&r1 = f();
	//无法将右值引用绑定到左值
	//!int &&r2 = vi[0];
	int &r2 = vi[0];
	//右值引用本身是左值，只能被左值引用
	int &r3 = r1;
	int &&r4 = vi[0] * f();
}

//由于String只有拷贝构造和赋值构造函数，因此vector的每一次reallocate都会对所有String进行一次拷贝
void Problem13_48() {
	vector<String> arr;
	for (int i = 0; i < 10; ++i) {
		cout << "size: "<<arr.size() << " " << "capacity: "<<arr.capacity() << endl;
		arr.push_back("123");
	}
}


//由于String定义了移动构造函数和移动赋值函数，vector在reallocate时会使用移动构造而不是拷贝构造
void Problem13_50() {
	vector<String> arr;
	String str("123");
	//对于右值引用，初始化时可能会根据右侧对象使用不同的构造函数来创造一个临时对象
	String &&tmp = "123";
	cout << tmp << endl;
	//如果添加的是一个左值，push_back会调用push_back(const val_type&)的重载函数，因此添加元素时是左值，使用拷贝构造，reallocate时会使用移动构造
	for (int i = 0; i < 5; ++i) {
		cout << "size: "<<arr.size() << " " << "capacity: "<<arr.capacity() << endl;
		arr.push_back(str);
	}
	//如果添加的是一个右值，push_back会调用push_back(val_type&&)的重载函数, 因此添加元素时是右值，使用移动构造 那么所有构造均为移动构造
	for (int i = 0; i < 5; ++i) {
		cout << "size: "<<arr.size() << " " << "capacity: "<<arr.capacity() << endl;
		arr.push_back("123");
	}
}

void Problem13_53() {
	HasPtr has_ptr_1("123");
	HasPtr has_ptr_2;
	has_ptr_2 = has_ptr_1;

	//operator=(HasPtr)不能与operator=(HasPtr&&)共存，对于右值实参两者具有相同的参数匹配优先级
	auto f = []()->HasPtr {
		HasPtr tmp("456");
		return tmp;
	};
	has_ptr_2 = std::move(has_ptr_1);
	has_ptr_2 = f();
}