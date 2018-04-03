#include"7.h"

void Problem7_00() {
	//输入，输出运算符重载
	SalesData salesData;
	cout << salesData << endl;
	SalesData salesData2("fuck", 1, 1);
	cout << salesData2 << endl;
	cin >> salesData2;
	cout << salesData2 << endl;

	//引用返回值(返回*this)
	salesData2
		.setIsbn("I want AD")
		.setUnitsSold(100)
		.setRevenue(3.14);
	cout << salesData2 << endl;

	//常量对象只能调用常量方法
	const SalesData salesData3;
	//salesData3.combine(salesData2);
	salesData3.isbn();

	//非默认构造函数的隐式类型转换
	string s = " CMU";
	salesData2.combine(s);
	cout << salesData2 << endl;
	s = " UCSD";
	salesData2.combine(static_cast<SalesData>(s));
	cout << salesData2 << endl;

	//声明为explicit方法的构造函数可以用显示强转进行初始化
	int i = 2;
	//salesData2.combine(i);
	salesData2.combine(static_cast<SalesData>(i));
	cout << salesData2 << endl;
}