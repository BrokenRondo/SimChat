#pragma once
#ifndef MSGREG_H
#define MSGREG_H
#include "MsgHead.h"

class MsgReg :public MsgHead
{
private:
	std::string name;
	std::string passwd;
public :
	std::string getName();
	std::string getPasswd();
	void setName(std::string name);
	void setPasswd(std::string passwd);

};

#endif
