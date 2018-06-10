#include"13_Message.h"

void Message::save(Folder &f) {
	folders.insert(&f);
	f.addMsg(this);
}

void Message::remove(Folder &f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::addFolder(Folder *pFolder){
	folders.insert(pFolder);
}

void Message::remFolder(Folder *pFolder){
	folders.erase(pFolder);
}

//拷贝控制成员
void Message::add_to_Folders(const Message &m) {
	for (auto &folder : m.folders) {
		folder->addMsg(this);
	}
}

Message::Message(const Message &m) :contents(m.contents), folders(m.folders) {
	add_to_Folders(m);
}

//析构
void Message::remove_from_Folders() {
	for (auto &folder : folders) {
		folder->remMsg(this);
	}
}

Message::~Message() {
	remove_from_Folders();
}

//拷贝赋值
//由于swap太复杂，因此不用swap
Message& Message::operator=(const Message &rhs) {
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}