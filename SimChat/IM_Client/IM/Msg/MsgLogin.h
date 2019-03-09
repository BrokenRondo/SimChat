#pragma once
#ifndef MSGLOGIN_H
#define MSGLOGIN_H
#include "MsgHead.h"

class MsgLogin :public MsgHead
{
private:
	std::string pwd;
	std::string JKNum;
public:
	MsgLogin(std::string JKNum, std::string pwd)
	{
		this->JKNum = JKNum;
		this->pwd = pwd;
	}
	MsgLogin();
	std::string getPwd();
	void setPwd(std::string pwd);
	/*std::string getJKNum();
	void setJKNum(std::string jkNum);*/
};
#endif
