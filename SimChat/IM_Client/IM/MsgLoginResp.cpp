#include "MsgLoginResp.h"

char MsgLoginResp::getState()
{
	return state;
}
void MsgLoginResp::setState(char state)
{
	this->state = state;  
}

