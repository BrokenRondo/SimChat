#pragma once
#ifndef SINGLELIST_H
#define SINGLELIST_H
#include <string>
#include "SingleItem.h"
#include <vector>

class SingleList//�������Ҫ�̳�
{
public:
	std::string listName;
	int bodyCount;//������ж��ٸ����Ѷ���
	int online;//��������
	int offline;
	std::vector<SingleItem> items;
};

#endif
