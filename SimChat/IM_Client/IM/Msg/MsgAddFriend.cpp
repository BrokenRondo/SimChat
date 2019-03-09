#include "MsgAddFriend.h"

int MsgAddFriend::getAdd_id()
{
	return src_id;
}

void MsgAddFriend::setAdd_id(int add_id)
{
	this->src_id = add_id;
}

std::string MsgAddFriend::getList_name()
{
	return src_add_list_name;
}

void MsgAddFriend::setlist_name(std::string list_name)
{
	this->src_add_list_name = list_name;
}

int MsgAddFriend::getPic()
{
	return pic;
}

void MsgAddFriend::setPic(int pic)
{
	this->pic = pic;
}
