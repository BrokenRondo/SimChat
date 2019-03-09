#include "socketSendTools.h"


void socketSendTools::run()
{
	while (!stopped)
	{
		if (MsgQueue.empty())
		{
			OS_Thread::Msleep(25);
			continue;
		}
		mtx.Lock();
		char* buf = new char[2048];
		memset(buf, 0, 2048);
		int len = MsgQueue.front()->length;
		memcpy(buf,MsgQueue.front()->buf, len);
		
		client_socket.Send(buf,len);
		mtx.Unlock();
		MsgQueue.pop();
		
		
		delete[] buf;
		
	}
	return;
}
