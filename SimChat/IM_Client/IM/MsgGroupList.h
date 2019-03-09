#pragma once
#ifndef MSGGROUPLIST_H
#define  MSGGROUPLIST_H
#include "Msg/MsgHead.h"
#include <vector>
using namespace ::std;
class MsgGroupList :public MsgHead
{
public:
	string userName;
	int pic;
	char listCount;
	vector<string>listName;
	vector<char>bodyCount;
	vector<vector<int> > bodyNum;
	vector<vector<int> > bodyPic;
	vector<vector<string> > nikeName;
	vector<vector<char> > bodyState;

};

#endif
