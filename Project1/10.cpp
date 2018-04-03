#include "10.h"

void Problem10_3() {
	vector<int> arr = { 1,2,3,4,5 };
	cout << accumulate(begin(arr), end(arr), 0) << endl;
}

//accumulate使用时注意：
//容器元素类型与初始值类型最好匹配，否则算法会将元素类型转换为输入参数的类型
void Problem10_4() {
	vector<double> arr = { 1.1, 1.2, 1.3 };
	cout << accumulate(begin(arr), end(arr), 0) << endl;
	//arr中的double元素都被转成了int
	//out: 3

	cout << accumulate(begin(arr), end(arr), 0.0) << endl;
	//out: 3.6
}

void Problem10_6() {
	vector<int> arr;
	fill_n(back_inserter(arr), 10, 0);
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;

}

//back_inserter配合copy可以对空容器进行拷贝初始化
void Problem10_7_1() {
	vector<int> vec ;
	//vector<int> vec = { 0 };
	//由于back_inserter执行的是push_back操作
	//所以最后输出是0,1,2,3
	list<int> lst = { 1,2,3 };
	copy(lst.cbegin(), lst.cend(), back_inserter(vec));
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
	auto it = back_inserter(vec);
}

//reserve只能保证vector的capacity，不能保证size
//fill_n要求size至少为n
void Problem10_7_2() {
	vector<int> vec;
	vec.clear();
	vec.reserve(10);
	vec.push_back(1);
	cout << vec.size() << " " << vec.capacity() << endl;
	//fill_n(vec.begin(), 10, 0);
	for (auto i : vec) {
		cout << i << " ";
	}
	cout << endl;
}

//闲的没事自己写了一个unique,时间O(n)，空间O(1)
vector<int>::iterator myUnique(vector<int>::iterator begin, vector<int>::iterator end) {
	if (end - begin < 2) {
		return end;
	}
	auto it = begin+1, it2 = begin+1, it3 = begin;
	while (it2 != end) {
		if (*it2 != *it3) {
			if (*it != *it2) {
				auto tmp = *it;
				*it = *it2;
				*it2 = tmp;
			}
			it++;
			it3++;
		}
		it2++;
	}
	return it;
}

void Problem10_9() {
	vector<int>arr = { 1,5,8,4,2,6,8,4,1,6 };
	sort(begin(arr), end(arr));
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	auto it = myUnique(begin(arr), end(arr));
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	arr.erase(it, end(arr));
	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Problem10_13() {
	vector<string> arr = { "1", "12", "123", "1234", "12345", "123456", "1234567", "1234567" };
	int len = 5;
	auto fun = [&](const auto &s) {return s.size() >= len; };
	auto p = partition(begin(arr), end(arr), fun);
	for (auto it = begin(arr); it != p; ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void Problem10_15() {
	int a = 1;
	auto fun = [a](int b) {return a + b; };
	cout << fun(1) << endl;
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
	sort(begin(words), end(words));
	auto it = unique(begin(words), end(words));
	words.erase(it, end(words));
	stable_sort(begin(words), end(words), [](const string &a, const string &b) {return a.length() < b.length(); });
	auto wc = stable_partition(begin(words), end(words), [sz](const auto &s) {return s.length() >= sz; });
	cout << wc - begin(words) << endl;
	for_each(begin(words), end(words), [](const auto& s) {cout << s << " "; });
	cout << endl;
}

void Problem10_19() {
	vector<string> arr = { "1", "12", "123", "1234", "12345", "123456", "1234567", "1234567" };
	int len = 5;
	biggies(arr, len);
}

//!注意: lambda传值捕获的变量不能在lambda函数体内修改，除非在参数列表后加一个mutable
void Problem10_20() {
	vector<string> arr = { "1", "12", "123", "1234", "12345", "123456", "1234567", "12345678" };
	int len = 6;
	auto fun = [=](const string &s)->bool {return s.length() >= len; };
	cout << count_if(begin(arr), end(arr), fun) << endl;
}

void Problem10_21() {
	int i = 10;
	auto fun = [&i]()->bool {
		while (i) { 
			cout << i << " ";
			i--; 
		}
		return i == 0;
	};
	cout << fun() << endl;
	cout << fun() << endl;
}

bool _Problem10_22(const string &s, int len) {
	return s.length() >= len;
}

//bind的_n在placeholders命名空间里，最好显示调用
void Problem10_22() {
	vector<string> arr = { "1", "12", "123", "1234", "12345", "123456", "1234567", "12345678" };
	int len = 6;
	cout << count_if(begin(arr), end(arr), bind(_Problem10_22, placeholders:: _1, len)) << endl;
}

bool _Problem10_24(int number, const string &str) {
	return number > str.length();
}
void Problem10_24() {
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	cout << *find_if(begin(arr), end(arr), bind(_Problem10_24, placeholders:: _1, "CMU")) << endl;
}

void _Problem10_25(vector<string> &words, string::size_type sz) {
	sort(begin(words), end(words));
	auto it = unique(begin(words), end(words));
	words.erase(it, end(words));
	stable_sort(begin(words), end(words), [](const string &a, const string &b) {return a.length() < b.length(); });
	auto wc = stable_partition(begin(words), end(words), bind(_Problem10_22, placeholders:: _1, sz));
	cout << wc - begin(words) << endl;
	for_each(begin(words), end(words), [](const auto& s) {cout << s << " "; });
	cout << endl;
}

void Problem10_25() {
	vector<string> arr = { "1", "12", "123", "1234", "12345", "123456", "1234567", "1234567" };
	int len = 5;
	_Problem10_25(arr, len);
}

void Problem10_27() {
	vector<int> vec = { 1,2,3,4,5 };
	list<int> lt;
	unique_copy(begin(vec), end(vec), back_inserter(lt));
	for (auto i : lt) {
		cout << i << " ";
	}
	cout << endl;
}

//用front迭代器初始化容器时，顺序与原容器相反
//其他迭代器初始化容器后的顺序与原容器同向
void Problem10_28() {
	vector<int> arr = { 1,2,3,4,5,6,7,8,9 };
	deque<int> dq;
	deque<int> dq2;
	list<int> lt;
	forward_list<int> flt;
	copy(begin(arr), end(arr), front_inserter(flt));
	copy(begin(arr), end(arr), inserter(dq, end(dq)));
	copy(begin(arr), end(arr), inserter(dq2, begin(dq2)));
	copy(begin(arr), end(arr), back_inserter(lt));

	auto print = [](const auto &i) {cout << i << " "; };
	for_each(begin(flt), end(flt), print);
	cout << endl;
	for_each(begin(dq), end(dq), print);
	cout << endl;
	for_each(begin(dq2), end(dq2), print);
	cout << endl;
	for_each(begin(lt), end(lt), print);
}

void Problem10_34_35() {
	vector<int> arr = { 1,2,3,4,5,6 };
	for (auto it = rbegin(arr); it != rend(arr); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	for (auto it = end(arr); it != begin(arr);) {
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

void Problem10_37() {
	vector<int> arr = { 1,2,3,4,5,6,7,8,9,0 };
	list<int> lt;
	copy(rbegin(arr) + arr.size() - 7, rend(arr) - 2, back_inserter(lt));
	for (auto i : lt) {
		cout << i << " ";
	}
	cout << endl;
}

void myListUnique(list<int> *plt) {
	auto bIt = begin(*plt);
	auto eIt = begin(*plt);
	eIt++;

	while (eIt != end(*plt)) {
		if (*eIt == *bIt) {
			eIt = plt->erase(eIt);
		}
		else {
			bIt = eIt;
			eIt++;
		}
	}
}

void _Problem10_42(list<int> *lt) {
	lt->sort();
	//lt->unique();
	myListUnique(lt);
	for (auto i : *lt) {
		cout << i << " ";
	}
	cout << endl;
}

void Problem10_42() {
	list<int> lt = {5,2,4,5,8,4,6,2,1,4,5,6,5,6 };
	_Problem10_42(&lt);
}