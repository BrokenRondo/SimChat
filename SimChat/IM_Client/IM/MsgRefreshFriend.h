#pragma once
#ifndef MSGREFRESH_H
#define MSGREFRESH_H
#include "Msg/MsgHead.h"

class MsgRefreshFriend:public MsgHead
{
public:
	MsgRefreshFriend(int jkNum,char online)
	{
		this->jkNum = jkNum;
		this->online = online;
	}
	int jkNum;//需要刷新的好友号码
	char online;//刷新好友是否在线
};
#endif
