#include "socket_waitPackage.h"

int socket_waitPackage::WaitBytes(OS_TcpSocket sock, void* buf, int count, int timeout)
{
	if (timeout > 0)
	{
		sock.SetOpt_RecvTimeout(timeout);
	}

	// 反复接收,直到接满指定的字节数
	int bytes_got = 0;
	while (bytes_got < count)
	{
		int n = sock.Recv((char*)buf + bytes_got, count - bytes_got);
		if (n <= 0)
		{
			return bytes_got;
		}

		bytes_got += n;
	}

	return bytes_got;
}
