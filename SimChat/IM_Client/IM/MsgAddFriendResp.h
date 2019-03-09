#pragma once
#ifndef  ADDFRIENDR_H
#define ADDFRIENDR_H
#include "Msg/MsgAddFriend.h"

class MsgAddFriendResp:public MsgAddFriend
{
private:
	char state;//是否同意，1为是，0为否
	int agree_id;//同意的人的号码
	std::string agree_listName;//同意的人将对方添加至的分组名
public:
	char getState();
	void setState(char state);
	int getAgreeId();
	void setAgreeId(int id);
	std::string getAgreeListName();
	void setAgreeListName(std::string name);
};
#endif
