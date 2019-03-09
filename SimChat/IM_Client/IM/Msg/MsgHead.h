#pragma once
#ifndef MSGHEAD_H
#define MSGHEAD_H
#include <string>
class MsgHead
{
private:
	int totalLen;
	char type;
	int dest;
	int src;
public:
	int getTotalLen();
	void setTotalLen(int totalLen);
	char getType();
	void setType(char type);
	int getDest();
	void setDest(int Dest);
	int getSrc();
	void setSrc(int Src);
	MsgHead(char type)
	{
		setType(type);
	}
	MsgHead(){}

};
#endif