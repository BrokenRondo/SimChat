#pragma once
#ifndef SEARCH_H
#define SEARCH_H
#include "Msg/MsgHead.h"

class MsgSearch:public MsgHead
{
public:
	MsgSearch(int jkNum)
	{
		this->jkNum = jkNum;
	}
	MsgSearch(){}
	int jkNum;
};
#endif
