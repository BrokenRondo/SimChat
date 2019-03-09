#pragma once
#ifndef MSGCHAT_H
#define MSGCHAT_H
#include "MsgHead.h"

class MsgChat:public MsgHead
{
private:
	std::string msgText;
public:
	std::string getMsgText();
	void setMsgText(std::string msgText);
	MsgChat(int from,int  target, std::string text);
	MsgChat() = default;;
};
#endif