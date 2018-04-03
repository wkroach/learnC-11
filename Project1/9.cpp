#include"9.h"

//C++11支持列表初始化,而且支持复杂容器的列表初始化(如下)
//根本原因是容器使用了initializer_list作为参数的构造函数
void Problem9_2() {
	list<deque<int>> lt = { {1,2,3}, {4,5} };
	auto it = lt.begin();
	it->push_back(0);
	it->pop_front();
	for (auto &dq : lt) {
		for (auto &i : dq) {
			cout << i << " ";
		}
		cout << endl;
	}
}

vector<int>::iterator _Problem9_5(vector<int>::iterator begin, vector<int>::iterator end, int i) {
	for (; begin != end; ++begin) {
		if (*begin == i) {
			return begin;
		}
	}
	return end;
}

void Problem9_5() {
	vector<int> arr = { 1,2,3,4,5 };
	auto testFun = [](auto begin, auto end, int i){auto it = _Problem9_5(begin, end, i); return it == end ? -1 : it - begin; };
	for (int i = 0; i <= 6; ++i) {
		cout << testFun(begin(arr), end(arr), i) << endl;
	}
}

//非const容器的迭代器都是非const，c开头迭代器都是const
//const容器的迭代器都是const
void Problem9_10() {
	vector<int> v1;
	const vector<int> v2;
	auto it1 = v1.begin();
	auto it2 = v2.begin();
	auto it3 = v1.cbegin();
	auto it4 = v2.cbegin();
}

//C++11的顺序容器支持如下初始化模式(其实还有更多)
void Problem9_11()
{
	vector<int> arr = { 1,2,3 };
	decltype(arr) arr2(10, 1);
	decltype(arr) arr3(arr);
	decltype(arr) arr4(10);
	decltype(arr) arr5(begin(arr), begin(arr) + 2);
	decltype(arr) arr6{ 4,5,6 };
	auto loop = [](auto &arr) {for (auto &i : arr) { cout << i << " "; } cout << endl; };
	loop(arr);
	loop(arr2);
	loop(arr3);
	loop(arr4);
	loop(arr5);
	loop(arr6);
}

//!重要：C++11支持容器的迭代器初始化, 且容器类型即元素类型都可以不一样，只要元素之间能够赋值就可以
void Problem9_13() {
	list<int> lt = { 1,2,3,4,5 };
	vector<int> arr1 = { 5,4,3,2,1 };
	vector<double> arr(begin(lt), end(lt));
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
	vector<double> arr2(begin(arr1), end(arr1));
	for (auto i : arr2) {
		cout << i << " ";
	}
	cout << endl;

}

//C++11的顺序容器支持assign操作，即重新初始化，参数与初始化构造函数的参数一致
void Problem9_14(){
	list<char*> lt = { "I", "want", "AD", "from", "CMU" };
	vector<string> arr = { "123", "456" };
	for (auto &s : arr) {
		cout << s << " ";
	}
	cout << endl;
	arr.assign(begin(lt), end(lt));
	for (auto &s : arr) {
		cout << s << " ";
	}
	cout << endl;
}

int _Problem9_16(const vector<int> &arr, const list<int> &lt) {
	auto it1 = begin(arr);
	auto it2 = begin(lt);
	for (; it1 != end(arr) && it2 != end(lt); ) {
		if (*it1 == *it2) {
			it1++;
			it2++;
		}
		else if (*it1 < *it2) {
			return -1;
		}
		else if (*it1 > *it2) {
			return 1;
		}
	}
	return it1 == end(arr) ? (it2 == end(lt) ? 0 : -1) : 1;
}

//顺序容器可以进行比较，比较满足以下条件
//1 字典序
//2 元素可以比较或重载了比较操作符<和=
void Problem9_16() {
	vector<int> arr = { 1,2,3,4,5 };
	list<int> lt = { 1,2,3,4 };
	cout << _Problem9_16(arr, lt) << endl;
}

//迭代器真他妈是个神器
void Problem9_18() {
	string s;
	deque<string> dq;
	while (cin >> s, s != "EOF") {
		dq.push_back(s);
	}
	for (auto it = begin(dq); it != end(dq); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void Problem9_19() {
	string s;
	list<string> lt;
	while (cin >> s, s != "EOF") {
		lt.push_back(s);
	}
	for (auto it = begin(lt); it != end(lt); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

void Problem9_20() {
	list<int> lt = { 1,2,3,4,5 };
	deque<int> dq1;
	deque<int> dq2;

	for (auto it = begin(lt); it != end(lt); it++) {
		if (*it % 2) {
			dq1.push_back(*it);
		}
		else {
			dq2.push_back(*it);
		}
	}
	for (auto i : dq1) {
		cout << i << " ";
	}
	cout << endl;
	for (auto i : dq2) {
		cout << i << " ";
	}
	cout << endl;
}

void Problem9_21() {
	vector<string> arr;
	auto it = begin(arr);
	string s;
	while (cin >> s, s != "EOF") {
		it = arr.insert(it, s);
		it++;
	}
	for (auto s : arr) {
		cout << s << " ";
	}
	cout << endl;
}

//!重要:容器一旦修改了大小，那么之前指向它的指针，引用，迭代器全部失效
//!重要:begin()和end()操作一定不能用临时变量保存并使用，必须直接调用，原因同上
void Problem9_22() {
	vector<int> iv = { 1,2,3,4,5 };
	auto iter = begin(iv);
	auto mid = begin(iv) + iv.size() / 2;
	while (iter != begin(iv) + iv.size()/2) {
		if (*iter == 2) {
			iter = iv.insert(iter, 2 * 2);
			iter++;
		}
		iter++;
	}
	for (auto i : iv) {
		cout << i << " ";
	}
	cout << endl;

}

void Problem9_24() {
	vector<int> arr = { 1,2,3 };
	arr.clear();
	cout << arr[0] << endl;
	//cout << arr.at(1) << " " << arr.front() << " " << *begin(arr) << endl;
}

void Problem9_25() {
	vector<int> arr = { 1,2,3,4,5 };
	arr.erase(end(arr), end(arr));
	arr.erase(begin(arr), begin(arr));
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

void Problem9_26() {
	int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
	list<int> lt(begin(ia), end(ia));
	vector<int> arr(begin(ia), end(ia));

	auto it1 = begin(lt);
	while (it1 != end(lt)) {
		if (*it1 & 1) {
			it1 = lt.erase(it1);
		}
		else {
			it1++;
		}
	}

	auto it2 = begin(arr);
	while (it2 != end(arr)) {
		if ((*it2 & 1) == 0) {
			it2 = arr.erase(it2);
		}
		else {
			it2++;
		}
	}
	for (auto i : lt) { cout << i << " "; }
	cout << endl;
	for (auto i : arr) { cout << i << " "; }
	cout << endl;
}

//C++11新容器forward_list，作为单向list性能比list要好，但是api与普通顺序容器有很大不同
//list和forward_list在erase和insert等操作后，原先指向它们的指针，引用，迭代器均有效
void Problem9_27() {
	forward_list<int> lt = { 0,1,1,2,3,5,8,13,21,34,55 };
	for (auto i : lt) {
		cout << i << " ";
	}
	cout << endl;

	auto pre = lt.before_begin();
	auto cur = lt.begin();
	while (cur != lt.end()) {
		if (*cur & 1) {
			cur = lt.erase_after(pre);
		}
		else {
			//!此时虽然对list进行了erase操作，但pre依旧有效，可以直接++
			pre++;
			cur++;
		}
	}
	for (auto i : lt) {
		cout << i << " ";
	}
	cout << endl;
}

void _Problem9_28(forward_list<string> *lt, string s1, string s2) {
	auto pre = lt->before_begin();
	auto cur = lt->begin();
	while (cur != lt->end()) {
		if (*cur == s1) {
			lt->insert_after(cur, s2);
			return;
		}
		else {
			pre = cur;
			cur++;
		}
	}
}

void Problem9_28() {
	forward_list<string> lt = { "I", "want", "AD", "from", "CMU" };
	_Problem9_28(&lt, "CMU", "and UCSD");
	for (auto &s : lt) {
		cout << s << " ";
	}
	cout << endl;
}

void Problem9_29() {
	vector<string> arr(25, "CMU");
	arr.resize(100);
	arr.resize(10);
	for (auto i : arr) {
		cout << i << " ";
	}
	cout << endl;
}

void Problem9_31() {
	list<int> lt = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = begin(lt);
	while (iter != end(lt)) {
		if (*iter & 1) {
			iter = lt.insert(iter, *iter);
			iter++, iter++;
		}
		else {
			iter = lt.erase(iter);
		}
	}
	for (auto i : lt) {
		cout << i << " ";
	}
	cout << endl;
}

void Problem9_38() {
	vector<int> arr;
	for (int i = 0; i < 100; ++i) {
		arr.push_back(i);
		cout << i<<" "<< arr.capacity() << endl;
	}
}

//测试reserve函数作用
//!vector在reserve后，capacity就会有对应大小的容量
void Problem9_39() {
	vector<int> arr;
	arr.reserve(100);
	cout << arr.size() << " " << arr.capacity() << endl;
	arr.assign(10, 1);
	cout << arr.size() << " " << arr.capacity() << endl;
	arr.assign(101, 1);
	cout << arr.size() << " " << arr.capacity() << endl;
}

void Problem9_41() {
	vector<char> arr = { 'I',' ', 'w', 'a', 'n', 't', ' ', 'A', 'D',' ', 'f', 'r', 'o', 'm',' ', 'C','M','U' };
	string s(begin(arr), end(arr));
	cout << s << endl;
}

void _Problem9_43(string *pS, string oldValue, string newValue) {
	int pos = pS->find(oldValue);
	if (pos == pS->npos) {
		return;
	}
	else {
		pS->replace(pos, oldValue.length(), newValue);
	}
}

void Problem9_43() {
	string s = "I want AD from CMU";
	_Problem9_43(&s, "CMU", "CMU and UCSD");
	cout << s << endl;
}

string _Problem9_45(const string &name, const string &prefix, const string &suffix) {
	return prefix + " " + name + " " + suffix;
}

void Problem9_45() {
	string name = "Ke Wu";
	string prefix = "Mr.";
	string suffix = "Phd";
	cout << _Problem9_45(name, prefix, suffix) << endl;
}

string _Problem9_46(const string &name, const string &prefix, const string &suffix) {
	string ans = prefix;
	ans.append(" ");
	ans.insert(ans.length(), name);
	ans.append(" ");
	ans.insert(ans.length(), suffix);
	return ans;
}

void Problem9_46() {
	string name = "Ke Wu";
	string prefix = "Mr.";
	string suffix = "Phd";
	cout << _Problem9_46(name, prefix, suffix) << endl;
}

void Problem9_47() {
	string s = "ab2c3d7R4E6";
	string number;
	string::size_type pos = 0;
	while (pos = s.find_first_of("0123456789", pos), pos != s.npos) {
		number += s[pos];
		pos++;
	}
	pos = 0;
	string charactar;
	while (pos = s.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", pos), pos != s.npos) {
		charactar += s[pos];
		pos++;
	}
	cout << number << " "<<charactar << endl;
}

void Problem9_50() {
	vector<string> arr = { "1", "2", "3" };
	int sum = 0;
	for (auto &s : arr) {
		sum += stoi(s);
	}
	cout << sum << endl;
}