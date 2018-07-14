#include"14_Employee.h"

ostream& operator << (ostream &os, const Employee &employee) {
	os << "age: " << employee.get_age() << '\n'
		<< "gender: " << employee.get_gender() << '\n'
		<< "rank: " << employee.get_rank() << '\n'
		<< "tittle: " << employee.get_tittle() << '\n'
		<< "salary: " << employee.get_salary();
	return os;
}

//流输入时可能会出现异常，因此必须考虑到输入异常并为空对象赋一个合理的值
istream& operator >> (istream &is, Employee &employee) {
	int age;
	string gender;
	int rank;
	string tittle;
	double salary;
	is >> age >> gender >> rank >> tittle >> salary;
	if (is) {
		cout << "debug" << endl;
		employee
			.set_age(age)
			.set_gender(gender)
			.set_rank(rank)
			.set_tittle(tittle)
			.set_salary(salary);
	}
	else {
		employee = Employee();
	}
	return is;
}

bool operator == (const Employee &lhs, const Employee &rhs) {
	return lhs.get_age() == rhs.get_age() &&
		lhs.get_gender() == rhs.get_gender() &&
		lhs.get_rank() == rhs.get_rank() &&
		lhs.get_tittle() == rhs.get_tittle() &&
		lhs.get_salary() == rhs.get_salary();
}

//含义相反的运算符可以相互复用
bool operator != (const Employee &lhs, const Employee &rhs) {
	return !(lhs == rhs);
}