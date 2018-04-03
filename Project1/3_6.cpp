#include"3.h"
using namespace std;

void Problem3_6()
/*
用不同的for遍历方法对二维数组进行遍历
*/
{
	int ia[3][4] = { {1,2,3,4}, {5,6,7,8},{9,10,11,12} };
	//直接用下标
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << ia[i][j] <<" ";
		}
		cout << endl;
	}
	//range for语句(不用auto)
	for (int (&row)[4] : ia) {
		for (int &col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	//range for语句(用auto)
	for(auto &row:ia){
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	//直接用指针
	for (int (*row)[4] = begin(ia); row != end(ia); ++row) {
		for (int *col = begin(*row); col != end(*row); ++col) {
			cout << *col << " ";
		}
		cout << endl;
	}
	//直接用指针(用auto)
	for (auto row = begin(ia); row != end(ia); ++row) {
		for (auto col = begin(*row); col != end(*row); ++col) {
			cout << *col << " ";
		}
		cout << endl;
	}
}


