#pragma once
#include<string>
#include<unordered_set>
#include<vector>

#include"13_Message.h"

class Message;
class Folder {
public:
	Folder() = default;
	Folder(const Folder &);
	Folder& operator = (const Folder &);
	~Folder();

	void addMsg(Message *);
	void remMsg(Message *);
private:
	std::unordered_set<Message*> messages;
	void add_to_Messages(const Folder &);
	void remove_from_Messages();
};
