#include"14.h"
using std::string;
using std::cout;
using std::endl;

//C++���ַ�����������ֱ����==, <, >�ȱȽ������, ���ͬstringһ��
void Problem14_3() {
	string tmp = "123";
	cout << ("123" == "123") << endl;
	cout << ("1" == "123") << endl;
	cout << ("2" < "123") << endl;
	cout << ("2" > "123") << endl;
	cout << (tmp == "123") << endl;
}

void Problem14_7() {
	String str = "123";
	cout << str << endl;
}

void Problem14_8() {
	Employee employee(18, "male", 1, "intern", 360);
	cout << employee << endl;
}

void Problem14_12() {
	Employee employee;
	cin >> employee;
	cout << employee << endl;
}

void Problem14_16() {
	cout << "test StrBlob:" << endl;
	StrBlob str_blob1 = { "123", "456" };
	StrBlob str_blob2 = str_blob1;
	StrBlob str_blob3 = { "123", "456" };
	//ָ��Ķ���һ��
	cout << (str_blob1 == str_blob2) << endl;
	//ָ��Ķ���һ����ֵһ��
	cout << (str_blob2 != str_blob3) << endl;

	cout << "test StrBlobPtr:" << endl;
	StrBlobPtr sbp1(str_blob1, 0);
	StrBlobPtr sbp2(str_blob1, 0);
	StrBlobPtr sbp3(str_blob1, 1);
	StrBlobPtr sbp4(str_blob3, 0);
	//ָ��Ķ���һ����ƫ����һ��
	cout << (sbp1 == sbp2) << endl;
	//ָ��Ķ���һ����ƫ������һ��
	cout << (sbp1 == sbp3) << endl;
	//ָ��Ķ���һ��
	cout << (sbp1 == sbp4) << endl;

	cout << "test StrVec:" << endl;
	StrVec str_vec1 = { "123", "456", "7" };
	StrVec str_vec2 = str_vec1;
	StrVec str_vec3;
	//ֵ���
	cout << (str_vec1 == str_vec2) << endl;
	//ֵ����
	cout << (str_vec1 == str_vec3) << endl;

	cout << "test String:" << endl;
	String str1 = "123";
	String str2 = str1;
	String str3 = "1234";
	cout << (str1 == str2) << endl;
	cout << (str1 == str3) << endl;
}

void Problem14_17() {
	Employee employee(20, "male", 1, "intern", 200);
	Employee employee2(20, "male", 1, "intern", 200);
	Employee employee3;
	cout << (employee == employee2) << endl;
	cout << (employee == employee3) << endl;
	cout << (employee != employee3) << endl;
}