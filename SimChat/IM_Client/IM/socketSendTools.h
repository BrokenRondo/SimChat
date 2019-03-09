#pragma once
#ifndef SOCKETTOOLS_H
#define SOCKETTOOLS_H
#include "osapi/osapi.h"
#include <queue>
#include <mutex>
#include "MsgText.h"
#include <qobjectdefs.h>
#include <QThread>

extern OS_TcpSocket client_socket;
extern std::queue<MsgText*> MsgQueue;
class socketSendTools : public QThread
{
	Q_OBJECT
public:
	socketSendTools(): stopped(false)
	{
		
	}

	void stop();
private:
	void run() override;
	volatile bool stopped;
	OS_Mutex mutex;
	OS_Mutex mtx;
};

#endif
