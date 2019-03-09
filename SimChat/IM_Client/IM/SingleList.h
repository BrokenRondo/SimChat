#pragma once
#ifndef SINGLELIST_H
#define SINGLELIST_H
#include <string>
#include "SingleItem.h"
#include <vector>

class SingleList//这个不需要继承
{
public:
	std::string listName;
	int bodyCount;//这个组有多少个好友对象
	int online;//在线人数
	int offline;
	std::vector<SingleItem> items;
};

#endif
