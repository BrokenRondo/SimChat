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
	int jkNum;//��Ҫˢ�µĺ��Ѻ���
	char online;//ˢ�º����Ƿ�����
};
#endif
