#pragma once
#ifndef  ADDFRIENDR_H
#define ADDFRIENDR_H
#include "Msg/MsgAddFriend.h"

class MsgAddFriendResp:public MsgAddFriend
{
private:
	char state;//�Ƿ�ͬ�⣬1Ϊ�ǣ�0Ϊ��
	int agree_id;//ͬ����˵ĺ���
	std::string agree_listName;//ͬ����˽��Է�������ķ�����
public:
	char getState();
	void setState(char state);
	int getAgreeId();
	void setAgreeId(int id);
	std::string getAgreeListName();
	void setAgreeListName(std::string name);
};
#endif
