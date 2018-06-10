#include"13_Folder.h"

//��������
Folder::Folder(const Folder &rhs):messages(rhs.messages){
	add_to_Messages(rhs);
}

//��ֵ����
Folder & Folder::operator=(const Folder &rhs){
	remove_from_Messages();
	messages = rhs.messages;
	add_to_Messages(rhs);
	return *this;
}

//����
Folder::~Folder(){
	remove_from_Messages();
}

//����һ��Message��ָ��
void Folder::addMsg(Message *pMessage){
	messages.insert(pMessage);
}

//ɾ��һ��Message��ָ��
void Folder::remMsg(Message *pMessage){
	messages.erase(pMessage);
}

//��this Folder��ӵ�rhs��ÿ��Message�����folders set��
void Folder::add_to_Messages(const Folder &rhs){
	for (auto &message : rhs.messages) {
		message->folders.insert(this);
	}
}

//��this Folder��messages�е�ÿ��Message�����folders set��ɾ��
void Folder::remove_from_Messages(){
	for (auto &message : messages) {
		message->folders.erase(this);
	}
}
