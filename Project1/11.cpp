#include "11.h"

void Problem11_4() {
	vector<string> arr = { "I", "want", "ad", "from", "CMU.", "I", "want", "AD", "from", "UCSD!!!", "I", "want", "AD", "from", "Columbia555" };
	unordered_map<string, int> mp;
	for (const string &s : arr) {
		string::size_type pos1 = s.find_first_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
		string::size_type pos2 = s.find_last_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ");
		auto tmp = s.substr(pos1, pos2 - pos1 + 1);
		transform(begin(tmp), end(tmp), begin(tmp), tolower);
		++mp[tmp];
	}
	for (auto &item : mp) {
		cout << item.first << " " << item.second << endl;
	}
}

void Problem11_7() {
	unordered_map<string, vector<string>> mp;
	mp["Wu"] = vector<string>({ "Ke Wu", "Di Wu" });
	mp["Yan"] = vector<string>({ "Zehui Yan", "Le Yan" });
	mp["Su"] = vector<string>({ "Pei Su", "Xiang Su" });
	for (auto &p : mp) {
		cout << p.first << " ";
		for (auto &s : p.second) {
			cout << s << " ";
		}
		cout << endl;
	}
}

//map和set的key必须定义或重载了<操作符
//vector，deque,string等顺序容器迭代器重载了<操作符，因此可以作为map和set的key
//list,forward_list的迭代器没有重载<操作符，因此无法作为map和set的key
void Problem11_10() {
	vector<int> arr = { 1,2,3,4,5 };
	list<int> lt = { 1,2,3,4,5 };
	auto arrIt = begin(arr);
	auto ltIt = begin(lt);
	map<vector<int>::iterator, int> mp = { {arrIt, 0}, {end(arr)-1, arr.size() - 1} };
	//map<list<int>::iterator, int> mp2 = { {begin(lt), 0}, {end(lt), lt.size() - 1} };
	for (auto &item: mp) {
		cout << *item.first << " " << item.second << endl;
	}
//	for (auto &item : mp2) {
//		cout << *item.first << " " << item.second << endl;
//	}
}

bool myCompare(const string &lhs, const string &rhs) {
	return lhs.length() < rhs.length();
}

//set和multiset支持自定义比较函数，在初始化模板时要用函数指针作为第2个模板参数
//自定义函数中，要严格定义<，且set会按照<进行排序，相等的会去掉
//multiset则会
void Problem11_11() {
	vector<string> arr = { "I", "want", "AD", "from", "CMU","and","UCSD" };
	set<string, bool (*)(const string &lhs, const string &rhs)> st(myCompare);
	multiset<string, bool(*)(const string &lhs, const string &rhs)> sst(myCompare);
	st.insert(begin(arr), end(arr));
	sst.insert(begin(arr), end(arr));
	for (auto &item : st) {
		cout << item << " ";
	}
	cout << endl;
	for (auto &item : sst) {
		cout << item << " ";
	}
	cout << endl;
}

void Problem11_13() {
	vector<pair<string, int>> arr;
	string s;
	int i;
	while (cin >> s >> i, s!="EOF"&i!=-1) {
		arr.push_back(make_pair(s, i));
	}
	for (auto &item : arr) {
		cout << item.first << " " << item.second << endl;
	}
}

//set,map没有push_back方法，因此不能用back_inserter
void Problem11_17() {
	auto print = [](auto &item) {cout << item << " "; };
	vector<string> arr = { "I", "want", "AD", "from", "CMU", "and", "AD", "from", "UCSD" };
	vector<string> arr2;
	vector<string> arr3;
	multiset<string> s1;
	multiset<string> s2;
	multiset<string> s3;
	multiset<string> s4;
	copy(begin(arr), end(arr), inserter(s1, end(s1)));
	for_each(begin(s1), end(s1), print);
	cout << endl;
	
	//copy(begin(arr), end(arr), back_inserter(s2));
	//for_each(begin(s2), end(s2), print);
	//cout << endl;

	copy(begin(s1), end(s1), inserter(arr2, end(arr2)));
	for_each(begin(arr2), end(arr2), print);
	cout << endl;

	copy(begin(s1), end(s1), back_inserter(arr3));
	for_each(begin(arr3), end(arr3), print);
	cout << endl;
}

//mp,set的cbegin返回的是::const_iterator
void Problem11_18() {
	map<string, int> mp = { {"CMU", 1} };
	map<string, int>::const_iterator map_it = mp.cbegin();
	auto map_it2 = mp.cbegin();
}

void Problem11_19() {
	multiset<string> mst = { "I", "want", "AD", "from", "CMU" };
	multiset<string>::iterator it = mst.begin();
}

void Problem11_28() {
	map<string, int> mp = { {"CMU AD", 3} };
	auto it = mp.find("UCSD");
	if (it == mp.end()) {
		cout << "cannot find UCSD" << endl;
	}
	mp["UCSD"] = 1;
	map<string, int>::iterator it2 = mp.find("CMU AD");
	if (it2 != mp.end()) {
		cout << it2->first << " " << it2->second << endl;
	}
}

void Problem11_29() {
	map<string, int> mp = { {"CMU AD", 3}, {"UCSD AD", 1},{"Columbia AD",1} };
	auto it = mp.lower_bound("Columbia");
	auto it2 = mp.upper_bound("Columbia");
	auto pair1 = mp.equal_range("Columbia");
	cout << it->first << " " << it->second << endl;
	cout << it2->first << " " << it2->second << endl;
	cout << endl;
	cout << pair1.first->first << " " << pair1.first->second << endl;
	cout << pair1.second->first << " " << pair1.second->second << endl;
}

void Problem11_37() {
	cout << hash<string>()("1") << endl;
	cout << hash<string>()("CMU") << endl;
	cout << hash<int>()(2) << endl;
}