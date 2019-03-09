#pragma once
#ifndef PACKAGETOOLS_H
#define  PACKAGETOOLS_H
#include "Msg_H.h"
#include "MsgAddFriendResp.h"
#include "MsgSearch.h"

class PackageTools
{
public:
	void packMsgLogin(char* msg,MsgLogin msglogin);
	void packMsgLoginResp(char* msg);
	void packMsgRegResp(char* msg);
	void packMsgGroupList(char* msg);
	void packMsgAddFriend(char* msg, MsgAddFriend *msg_add_friend);
	void packMsgChat(char* msg, MsgChat *msg_chat);
	void packMsgAddFriendResp(char* msg, MsgAddFriendResp* msg_add_friend_resp);
	void packMsgSearch(char* msg, MsgSearch* m_search);
	void packMsgReg(char* msg, MsgReg *mreg);
	
private:
	void writeString(char* a, char* b,int len);
	void writeHead(char* a, MsgHead msg_head);
	void writeHead(char* a, MsgHead *msg_head);
	void writeInt(char*& a, int b);
	void writeChar(char*& a);
};

#endif
