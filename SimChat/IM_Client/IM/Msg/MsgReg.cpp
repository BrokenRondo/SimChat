#include "MsgReg.h"

std::string MsgReg::getName()
{
	return name;
}
std::string MsgReg::getPasswd()
{
	return passwd;
}
void MsgReg::setName(std::string name)
{
	this->name = name;
}
void MsgReg::setPasswd(std::string passwd)
{
	this->passwd = passwd;
}




