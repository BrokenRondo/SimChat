#pragma once
#ifndef MSGADDFRIEND_H
#define MSGADDFRIEND_H
#include "MsgHead.h"

class MsgAddFriend:public MsgHead
{
private:
	int src_id;
	std::string src_add_list_name;//����������ӵ��ĸ�����
	int pic;//�����ߵ�ͷ��
public:
	int getAdd_id();
	void setAdd_id(int add_id);
	std::string getList_name();
	void setlist_name(std::string list_name);
	int getPic();
	void setPic(int pic);
};

#endif
