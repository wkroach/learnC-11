#include"4.h"
using namespace std;

void Problem4_28() {
	cout << sizeof(int) << endl;
	cout << sizeof(int*) << endl;
	cout << sizeof(float) << endl;
	cout << sizeof(float*) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(long) << endl;
	cout << sizeof(long*) << endl;
	cout << sizeof(long long) << endl;
	cout << sizeof(long long*) << endl;
}

void Problem4_29() {
	int x[10]; int *p = x;
	cout << sizeof(x) / sizeof(*x) << endl;
	cout << sizeof(p) / sizeof(*p) << endl;
}

void Problem4_37() {
	int i=1;
	double d=2.5;
	string s = "123";
	const string *ps = &s;
	char ch = 'a';
	char *pc = &ch;
	void *pv = nullptr;

	pv = const_cast<string*>(ps); //pv = (void*)ps;
	cout << *static_cast<string*>(pv) << endl;

	i = static_cast<int>(*pc); //i = int(*pc)
	cout << i << endl;

	pv = static_cast<void*>(&d); //pv = &d
	cout << *static_cast<int*>(pv) << endl;
	cout << *static_cast<double*>(pv) << endl;

	pc = static_cast<char*>(pv); //pc = (char*)pv
	cout << pc << endl;
}

void Problem4_38() {
	int j = 5, i = 2;
	double slope = static_cast<double>(j / i);
	cout << slope << endl;
}