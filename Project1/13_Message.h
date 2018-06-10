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
	//�ڸ�����Folder����ӣ�ɾ��Message
	void save(Folder&);
	void remove(Folder&);
	void addFolder(Folder*);
	void remFolder(Folder*);
private:
	std::string contents;
	std::unordered_set<Folder*> folders;
	//��this Message���뵽����m��Folders��
	void add_to_Folders(const Message& m);
	//�Ӱ���this Message��Folders��ɾ��Message
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