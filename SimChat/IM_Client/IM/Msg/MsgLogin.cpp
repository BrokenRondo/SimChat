#include "MsgLogin.h"

MsgLogin::MsgLogin()
{
}

std::string MsgLogin::getPwd()
{
	return pwd;
}

void MsgLogin::setPwd(std::string pwd)
{
	this->pwd = pwd;
}
//std::string MsgLogin::getJKNum()
//{
//	return JKNum;
//}
//void MsgLogin::setJKNum(std::string jkNum)
//{
//	this->JKNum = jkNum;
//}


