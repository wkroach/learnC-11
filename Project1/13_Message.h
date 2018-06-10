#pragma once
#include<string>
#include<unordered_set>
#include<vector>

#include"13_Folder.h"

class Folder;
class Message {
	friend void swap(Message &lhs, Message &rhs);
	friend class Folder;
public:
	explicit Message(const std::string &str = "") :contents(str) {}
	Message(const Message&);
	Message& operator=(const Message&);
	~Message();
	//在给定的Folder中添加，删除Message
	void save(Folder&);
	void remove(Folder&);
	void addFolder(Folder*);
	void remFolder(Folder*);
private:
	std::string contents;
	std::unordered_set<Folder*> folders;
	//将this Message加入到包含m的Folders中
	void add_to_Folders(const Message& m);
	//从包含this Message的Folders中删除Message
	void remove_from_Folders();
};

void swap(Message &lhs, Message &rhs) {
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);
}