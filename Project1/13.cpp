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
