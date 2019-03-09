#pragma once
#ifndef SEARCHRESULT_H
#define SEARCHRESULT_H
#include "MsgSearch.h"

class MsgSearchResult:public MsgSearch
{
	
public:
	MsgSearchResult() {};
	std::string nickname;
	int pic;
	char result;
};
#endif
