#pragma once
#ifndef SWPACKAGE_H
#define SWPACKAGE_H
#include "osapi/osapi.h"

class socket_waitPackage
{
public:
	// ����ָ�����ȵ��ֽ�����
	// count: ׼�����ն����ֽ�
	// timeout: ���Ϊ0����ʾ�����ȴ������򣬱�ʾ���ý��ճ�ʱ
	static int WaitBytes(OS_TcpSocket sock,
		void* buf,
		int count,
		int timeout = 0);
};

#endif
