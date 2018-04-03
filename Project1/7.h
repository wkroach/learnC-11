#pragma once
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<initializer_list>
using namespace std;

class SalesData {
	friend ostream& operator <<(ostream& out, const SalesData &rhs);
	friend istream& operator >>(istream& in, SalesData &rhs);

  private:
	string bookNo;
	unsigned unitsSold=0;
	double revenue=0;

	//只有静态int，longlong，unsigned，char可以在类内初始化
	static const int id = 100;

  public:
	  SalesData()=default;
	  //隐式转化只对单一参数构造函数有效，所以单一参数构造函数尽量声明为explicit
	  SalesData(const string& bookNo) :bookNo(bookNo) {}
	  explicit SalesData(int bookNumber):bookNo(to_string(bookNumber)) {}

	  SalesData(const string& bookNo, unsigned unitsSold, double revenue) :
		  bookNo(bookNo), unitsSold(unitsSold), revenue(revenue) {}

	  string isbn() const {
		  return bookNo;
	  }
	  SalesData &setIsbn(const string& isbn) {
		  bookNo = isbn;
		  return *this;
	  }
	  SalesData &setUnitsSold(unsigned unitsSold) {
		  this->unitsSold = unitsSold;
		  return *this;
	  }
	  SalesData &setRevenue(double revenue) {
		  this->revenue = revenue;
		  return *this;
	  }
	  SalesData & combine(const SalesData &rhs) {
		  bookNo += rhs.bookNo;
		  unitsSold += rhs.unitsSold;
		  revenue += rhs.revenue;
		  return *this;
	  }
	  SalesData operator +(const SalesData &rhs) const {
		  SalesData salesDataTemp(*this);
		  salesDataTemp.unitsSold += rhs.unitsSold;
		  salesDataTemp.revenue += rhs.revenue;
		  return salesDataTemp;
	  }
};

inline ostream& operator <<(ostream& out, const SalesData &rhs) {
		  out << "bookNo: " << rhs.bookNo << " "
			  << "unitsSold: " << rhs.unitsSold << " "
			  << "revenue: " << rhs.revenue << endl;
		  return out;
}
inline istream& operator >>(istream& in, SalesData &rhs) {
		  in >> rhs.bookNo >> rhs.unitsSold >> rhs.revenue;
		  return in;
}

void Problem7_00();
