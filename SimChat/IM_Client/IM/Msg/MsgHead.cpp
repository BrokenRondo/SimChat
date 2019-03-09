#include "MsgHead.h"

int MsgHead::getTotalLen()
{
	return totalLen;
}
void MsgHead::setTotalLen(int totalLen)
{
	this->totalLen = totalLen;
}
char MsgHead::getType()
{
	return type;
}
void MsgHead::setType(char type)
{
	this->type = type;
}
int MsgHead::getDest()
{
	return dest;
}
void MsgHead::setDest(int Dest)
{
	this->dest = Dest;
}
int MsgHead::getSrc()
{
	return src;
}
void MsgHead::setSrc(int Src)
{
	this->src = Src;
}





