#include"7.h"

void Problem7_00() {
	//���룬������������
	SalesData salesData;
	cout << salesData << endl;
	SalesData salesData2("fuck", 1, 1);
	cout << salesData2 << endl;
	cin >> salesData2;
	cout << salesData2 << endl;

	//���÷���ֵ(����*this)
	salesData2
		.setIsbn("I want AD")
		.setUnitsSold(100)
		.setRevenue(3.14);
	cout << salesData2 << endl;

	//��������ֻ�ܵ��ó�������
	const SalesData salesData3;
	//salesData3.combine(salesData2);
	salesData3.isbn();

	//��Ĭ�Ϲ��캯������ʽ����ת��
	string s = " CMU";
	salesData2.combine(s);
	cout << salesData2 << endl;
	s = " UCSD";
	salesData2.combine(static_cast<SalesData>(s));
	cout << salesData2 << endl;

	//����Ϊexplicit�����Ĺ��캯����������ʾǿת���г�ʼ��
	int i = 2;
	//salesData2.combine(i);
	salesData2.combine(static_cast<SalesData>(i));
	cout << salesData2 << endl;
}