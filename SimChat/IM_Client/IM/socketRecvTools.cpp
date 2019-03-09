#include "socketRecvTools.h"
#include "osapi/Socket.h"
#include <Msg_H.h>
#include "socket_waitPackage.h"
#include "parseTool.h"
#include "LitterIem.h"
#include "MyMessageBox.h"
#include "Search.h"
#include "MsgSearch.h"
#include "MainForm.h"

extern std::vector<LitterIem*> litterIems;//用来保存好友的LitterIem
extern MainForm* mainform;
extern OS_TcpSocket client_socket;
extern Search* searchWidget;
extern string src_listName;
void socketRecvTools::run()
{
	
	char *buf = new char[2048];
	int iMode = 1;
	int retVal = ioctlsocket(client_socket.hSock, FIONBIO, (u_long FAR*) &iMode);//设置为非阻塞模式
	if (retVal == SOCKET_ERROR)
	{
		printf("ioctlsocket failed!\n"); 
		WSACleanup(); 
		return ;
	}
	
	while (!stopped)
	{
		mtx.lock();
		int n=client_socket.Recv(buf, 4);
		mtx.unlock();
		if (n<0)
		{
			OS_Thread::Msleep(25);
			continue;
		}
		//首先要判断长度
		int pack_len[1];
		memcpy(pack_len, buf, 4);
		pack_len[0] = ntohl(pack_len[0]) - 4;//减去用来表示长度的四位
		//然后再读取一定长度
		socket_waitPackage socket_wait;
		socket_wait.WaitBytes(client_socket, buf, pack_len[0], 0);
		parseTool *ptool = new  parseTool();
		char* buf_s = buf;
		if (buf[0]==0x04)//如果是发送过来的聊天消息
		{
			MsgChat *mchat = ptool->parse_chat(buf_s, pack_len[0]);
			//找到对应的好友number的litterIem
			int num = mchat->getSrc();
			int i = 0;
			for ( i = 0; i < litterIems.size(); i++)
			{
				if (litterIems[i]->getJkNum()==num)
				{
					break;
				}
			}
			if (i>=litterIems.size())
			{
				qDebug()<<"Message is not friend's";
				continue;
			}
			if (litterIems[i]->isOpen == false && litterIems[i]->m_mbox == false)//没打开窗口也没初始化
			{
				emit initChat(litterIems[i]->getJkNum(), QString::fromStdString(mchat->getMsgText()));
				emit Messagebox(litterIems[i]->getJkNum(), QString::fromStdString(mchat->getMsgText()));
				litterIems[i]->setNotice();
			}
			else if (litterIems[i]->isOpen)//
			{
				litterIems[i]->chat->recvShowMsg(QString::fromStdString(mchat->getMsgText()));
				litterIems[i]->chat->alert();//任务栏闪烁
			}
			else if(litterIems[i]->isInited&& litterIems[i]->m_mbox)//初始化了窗口并且有弹窗
			{
				//把窗口初始化好但是不打开
				litterIems[i]->chat->recvShowMsg(QString::fromStdString(mchat->getMsgText()));
				litterIems[i]->m_msgBox->m->addMsg(QString::fromStdString(mchat->getMsgText()));
				
				
			}else if (litterIems[i]->isInited&&!litterIems[i]->m_mbox)//窗口初始化并且没通知
			{
				//litterIems[i]->m_msgBox->m->addMsg(QString::fromStdString(mchat->getMsgText()));
			}

		}
		else if (buf[0]==0x77)//如果发过来的是刷新好友的消息
		{
			MsgRefreshFriend* mrefresh = ptool->parse_refresh(buf_s);
			//然后找到jknum对应的litterIem，刷新窗口
			int i = 0;
			for (i = 0; i < litterIems.size(); i++)
			{
				if (litterIems[i]->getJkNum() == mrefresh->jkNum)
				{
					break;
				}
			}
			if (i >= litterIems.size())
			{
				qDebug() << "Message is not friend's";
				continue;
			}
			litterIems[i]->refreshPic(mrefresh->online);

		}
		else if(buf[0]==0x75)//如果是添加好友的消息
		{
			MsgAddFriend *m_AddFriend = ptool->parse_add(buf_s);

			emit FriendBox(m_AddFriend->getPic(), m_AddFriend->getAdd_id());
			src_listName = m_AddFriend->getList_name();
			
		}
		else if(buf[0]==0x34)//如果是搜索用户的消息
		{
			MsgSearchResult *m_searchresult = ptool->parse_m_result(buf_s);
			if (m_searchresult->result==0x00)
			{
				mainform->result(0, "", 0);
			}
			//emit ShowResult(m_searchresult->pic, m_searchresult->nickname, m_searchresult->result);
			mainform->result(m_searchresult->pic, m_searchresult->nickname, m_searchresult->result);
		}else if(buf[0]==0x15)
		{
			MsgAddFriendConfirm *mConfirm = ptool->parse_Confirm(buf_s);
			emit AddFriendConfirm(mConfirm->newJKNum, mConfirm->newPic, (char*)mConfirm->newNickName.c_str(), (char*)mConfirm->newListName.c_str());
		}
	}
}
