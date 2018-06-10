#include"13_Folder.h"

//拷贝构造
Folder::Folder(const Folder &rhs):messages(rhs.messages){
	add_to_Messages(rhs);
}

//赋值构造
Folder & Folder::operator=(const Folder &rhs){
	remove_from_Messages();
	messages = rhs.messages;
	add_to_Messages(rhs);
	return *this;
}

//析构
Folder::~Folder(){
	remove_from_Messages();
}

//新增一个Message的指针
void Folder::addMsg(Message *pMessage){
	messages.insert(pMessage);
}

//删除一个Message的指针
void Folder::remMsg(Message *pMessage){
	messages.erase(pMessage);
}

//将this Folder添加到rhs的每个Message对象的folders set中
void Folder::add_to_Messages(const Folder &rhs){
	for (auto &message : rhs.messages) {
		message->folders.insert(this);
	}
}

//将this Folder从messages中的每个Message对象的folders set中删除
void Folder::remove_from_Messages(){
	for (auto &message : messages) {
		message->folders.erase(this);
	}
}
