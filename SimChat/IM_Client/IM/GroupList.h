#pragma once
#ifndef GROUPLIST_H
#define GROUPLIST_H
#include <vector>
#include "SingleList.h"

class GroupList
{
public:
	std::string ownerName;
	std::vector<SingleList> groupList;
};

#endif
