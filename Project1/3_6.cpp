#include"3.h"
using namespace std;

void Problem3_6()
/*
�ò�ͬ��for���������Զ�ά������б���
*/
{
	int ia[3][4] = { {1,2,3,4}, {5,6,7,8},{9,10,11,12} };
	//ֱ�����±�
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << ia[i][j] <<" ";
		}
		cout << endl;
	}
	//range for���(����auto)
	for (int (&row)[4] : ia) {
		for (int &col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	//range for���(��auto)
	for(auto &row:ia){
		for (auto col : row) {
			cout << col << " ";
		}
		cout << endl;
	}
	//ֱ����ָ��
	for (int (*row)[4] = begin(ia); row != end(ia); ++row) {
		for (int *col = begin(*row); col != end(*row); ++col) {
			cout << *col << " ";
		}
		cout << endl;
	}
	//ֱ����ָ��(��auto)
	for (auto row = begin(ia); row != end(ia); ++row) {
		for (auto col = begin(*row); col != end(*row); ++col) {
			cout << *col << " ";
		}
		cout << endl;
	}
}


