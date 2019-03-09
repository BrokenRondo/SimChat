#include "MsgAddFriendResp.h"

char MsgAddFriendResp::getState()
{
	return state;
}

void MsgAddFriendResp::setState(char state)
{
	this->state = state;
}

int MsgAddFriendResp::getAgreeId()
{
	return agree_id;
}

void MsgAddFriendResp::setAgreeId(int id)
{
	this->agree_id = id;
}

std::string MsgAddFriendResp::getAgreeListName()
{
	return agree_listName;
}

void MsgAddFriendResp::setAgreeListName(std::string name)
{
	this->agree_listName = name;
}
