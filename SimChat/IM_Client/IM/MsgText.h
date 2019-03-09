#pragma once
#ifndef MSGTEXT_H
#define MSGTEXT_H
class MsgText
{
public:
	char* buf;
	int length;
	MsgText()
	{
		buf = new char[2048];
	}
	MsgText(char* buf,int length)
	{
		this->buf = new char[length + 1];
		memcpy(this->buf, buf, length);
		this->length = length;
	}
};

#endif
