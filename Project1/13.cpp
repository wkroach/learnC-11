#include "13.h"

void Problem13_1() {
	string str = "123";
	A a = "123";
	A c = str;
	//ʹ���˿�����ֵ�����������ڹ��캯�����ڣ�����str��A����ʽת����
	c = str;
	A b;
	//�ǳ�ʼ��ʱ�ĸ�ֵ��ʹ��(�ϳ�)������ֵ����
	b = a;
	//��ʼ��ʱ�ĸ�ֵ��ֱ�ӳ�ʼ������ʹ��(�ϳɵ�)�������캯�������綨���˾ͱ���Ϊpublic
	A aa(b);
	A aaa = b;
}

A foo_bar(A arg) {
	/*
	��������������βγ�ʼ����������ʼ����new / shared_ptr��ʼ������������ֵ��ʼ��
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
	//�ǵý�numbered�еĿ������캯��ע�͵�
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
	//����
	StrVec strVec = { "123", "456", "789" };
	for_each(begin(strVec), end(strVec), loop);
	cout << endl;
	//��������
	StrVec strVec2(strVec);
	for_each(begin(strVec2), end(strVec2), loop);	
	cout << endl;
	//push_back
	strVec2.push_back("101112");
	for_each(begin(strVec2), end(strVec2), loop);
	cout << endl;
	//��ֵ����
	StrVec strVec3;
	strVec3 = strVec2;
	for_each(begin(strVec3), end(strVec3), loop);
	cout << endl;
	//�Ը�ֵ
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
	//�޷�����ֵ���ð󶨵���ֵ
	//!int &&r2 = vi[0];
	int &r2 = vi[0];
	//��ֵ���ñ�������ֵ��ֻ�ܱ���ֵ����
	int &r3 = r1;
	int &&r4 = vi[0] * f();
}

//����Stringֻ�п�������͸�ֵ���캯�������vector��ÿһ��reallocate���������String����һ�ο���
void Problem13_48() {
	vector<String> arr;
	for (int i = 0; i < 10; ++i) {
		cout << "size: "<<arr.size() << " " << "capacity: "<<arr.capacity() << endl;
		arr.push_back("123");
	}
}


//����String�������ƶ����캯�����ƶ���ֵ������vector��reallocateʱ��ʹ���ƶ���������ǿ�������
void Problem13_50() {
	vector<String> arr;
	String str("123");
	//������ֵ���ã���ʼ��ʱ���ܻ�����Ҳ����ʹ�ò�ͬ�Ĺ��캯��������һ����ʱ����
	String &&tmp = "123";
	cout << tmp << endl;
	//�����ӵ���һ����ֵ��push_back�����push_back(const val_type&)�����غ�����������Ԫ��ʱ����ֵ��ʹ�ÿ������죬reallocateʱ��ʹ���ƶ�����
	for (int i = 0; i < 5; ++i) {
		cout << "size: "<<arr.size() << " " << "capacity: "<<arr.capacity() << endl;
		arr.push_back(str);
	}
	//�����ӵ���һ����ֵ��push_back�����push_back(val_type&&)�����غ���, ������Ԫ��ʱ����ֵ��ʹ���ƶ����� ��ô���й����Ϊ�ƶ�����
	for (int i = 0; i < 5; ++i) {
		cout << "size: "<<arr.size() << " " << "capacity: "<<arr.capacity() << endl;
		arr.push_back("123");
	}
}

void Problem13_53() {
	HasPtr has_ptr_1("123");
	HasPtr has_ptr_2;
	has_ptr_2 = has_ptr_1;

	//operator=(HasPtr)������operator=(HasPtr&&)���棬������ֵʵ�����߾�����ͬ�Ĳ���ƥ�����ȼ�
	auto f = []()->HasPtr {
		HasPtr tmp("456");
		return tmp;
	};
	has_ptr_2 = std::move(has_ptr_1);
	has_ptr_2 = f();
}