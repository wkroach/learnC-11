#include"6.h"

/*��������intָ�룬2��ָ�뽻��*/
void Problem6_22(int **ppa, int **ppb) {
	int *ptmp = nullptr;
	ptmp = *ppa;
	*ppa = *ppb;
	*ppb = ptmp;
}

/*��������intָ�룬ָ�����ý���*/
void Problem6_22(int *&pa, int *&pb) {
	int *ptmp = nullptr;
	ptmp = pa;
	pa = pb;
	pb = ptmp;
}

void Problem6_24(const int ia[10]) {
	for (size_t i = 0; i != 10; ++i) {
		cout << ia[i] << endl;
	}
}

int &Problem6_32(int *arry, int index) {
	return arry[index];
}

string strArr[5] = { "1", "2", "3", "4", "5" };
string strArr2[5] = { "5", "4", "3", "2", "1" };

/*�������������*/
string (&Problem6_36(int i))[5]{
	if (i & 1) {
		return strArr;
	}
	else{
		return strArr2;
	}
}

/*������������ã���β�÷������Ͷ���*/
auto Problem6_37(int i)->string(&)[5]{
	if (i & 1) {
		return strArr;
	}
	else {
		return strArr2;
	}
}

void Problem6_47(const vector<int>& arr, int depth) {
	if (depth == arr.size()) {
		return;
	}
#ifndef NDEBUG
	cout << "depth " << depth << endl;
#endif
	cout << arr[depth] << endl;
	Problem6_47(arr, depth + 1);
	return;
}

int Problem6_54(int a, int b) {
	return a + b;
}
int Problem6_55(int a, int b) {
	return a - b;
}
int Problem6_56(int a, int b) {
	return a*b;
}
int Problem6_57(int a, int b) {
	return a / b;
}
void Problem6_58() {
	vector<int(*)(int, int)>arr;
	arr.push_back(Problem6_54);
	arr.push_back(Problem6_55);
	arr.push_back(Problem6_56);
	arr.push_back(Problem6_57);
	for (const auto& fun : arr) {
		cout << fun(4, 3) << endl;
	}
}
