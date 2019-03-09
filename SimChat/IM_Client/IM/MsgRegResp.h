#pragma once
#include "Msg/MsgHead.h"

class MsgRegResp:public MsgHead
{
public:
	char state;
	int JKNum;
};
