#pragma once
#ifndef CONFIRM_H
#define CONFIRM_H
#include "Msg/MsgHead.h"

class MsgAddFriendConfirm:public MsgHead
{
public:
	int srcJKNum;
	int newJKNum;
	int newPic;
	std::string newListName;
	std::string newNickName;
};
#endif
