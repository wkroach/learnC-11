#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using std::ostream;
using std::istream;
using std::cout; 
using std::cin;
using std::endl;
using std::string;

class Employee {
public:
	friend ostream& operator << (ostream&, const Employee&);
	friend istream& operator >> (istream&, Employee&);
	friend bool operator == (const Employee&, const Employee&);
	friend bool operator != (const Employee&, const Employee&);

	Employee():Employee(0, "unknown", 0, "unknown", 0.0){}
	Employee(int age, string gender, int rank, string tittle, double salary) :
		_age(age), _gender(gender), _rank(rank), _tittle(tittle), _salary(salary) {}

	int get_age() const {
		return _age;
	}
	Employee& set_age(int age) {
		_age = age;
		return *this;
	}

	string get_gender() const {
		return _gender;
	}
	Employee& set_gender(string gender) {
		_gender = gender;
		return *this;
	}

	int get_rank() const {
		return _rank;
	}
	Employee& set_rank(int rank) {
		_rank = rank;
		return *this;
	}

	string get_tittle() const {
		return _tittle;
	}
	Employee& set_tittle(string tittle) {
		_tittle = tittle;
		return *this;
	}

	double get_salary() const {
		return _salary;
	}
	Employee& set_salary(double salary) {
		_salary = salary;
		return *this;
	}
private:
	int _age;
	string _gender;
	int _rank;
	string _tittle;
	double _salary;
};