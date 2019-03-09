#pragma once
#ifndef PARSETOOL_H
#define PARSETOOL_H
#include <string>
#include "Msg_H.h"
#include "GroupList.h"
#include "MsgRefreshFriend.h"
#include "MsgSearchResult.h"
#include "MsgAddFriendConfirm.h"
#include "MsgRegResp.h"


class parseTool
{
private:
	std::string readString(char*& buf, int len);
	int readInt(char*& buf);
	char readChar(char* &buf);
public:
	MsgLoginResp parse_msg_login_resp(char*& buf,int len);
	MsgGroupList parse_group_list(char*&buf, int len);
	GroupList parse_list(MsgGroupList group_list);
	MsgChat *parse_chat(char*& buf, int len);
	MsgRefreshFriend* parse_refresh(char*& buf);
	MsgAddFriend *parse_add(char*& buf);
	MsgSearchResult* parse_m_result(char*& buf);
	MsgAddFriendConfirm* parse_Confirm(char*& buf);
	MsgRegResp *parse_RegResp(char*& buf);
};



#endif