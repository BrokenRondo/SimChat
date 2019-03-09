#pragma once
#ifndef MSGLOGINR_H
#define MSGLOGINR_H
#include "Msg/MsgHead.h"

class MsgLoginResp:public MsgHead
{
private:
	char state;
public :
	char getState();
	void setState(char state);
};

#endif
