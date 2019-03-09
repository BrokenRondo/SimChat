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

extern std::vector<LitterIem*> litterIems;//����������ѵ�LitterIem
extern MainForm* mainform;
extern OS_TcpSocket client_socket;
extern Search* searchWidget;
extern string src_listName;
void socketRecvTools::run()
{
	
	char *buf = new char[2048];
	int iMode = 1;
	int retVal = ioctlsocket(client_socket.hSock, FIONBIO, (u_long FAR*) &iMode);//����Ϊ������ģʽ
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
		//����Ҫ�жϳ���
		int pack_len[1];
		memcpy(pack_len, buf, 4);
		pack_len[0] = ntohl(pack_len[0]) - 4;//��ȥ������ʾ���ȵ���λ
		//Ȼ���ٶ�ȡһ������
		socket_waitPackage socket_wait;
		socket_wait.WaitBytes(client_socket, buf, pack_len[0], 0);
		parseTool *ptool = new  parseTool();
		char* buf_s = buf;
		if (buf[0]==0x04)//����Ƿ��͹�����������Ϣ
		{
			MsgChat *mchat = ptool->parse_chat(buf_s, pack_len[0]);
			//�ҵ���Ӧ�ĺ���number��litterIem
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
			if (litterIems[i]->isOpen == false && litterIems[i]->m_mbox == false)//û�򿪴���Ҳû��ʼ��
			{
				emit initChat(litterIems[i]->getJkNum(), QString::fromStdString(mchat->getMsgText()));
				emit Messagebox(litterIems[i]->getJkNum(), QString::fromStdString(mchat->getMsgText()));
				litterIems[i]->setNotice();
			}
			else if (litterIems[i]->isOpen)//
			{
				litterIems[i]->chat->recvShowMsg(QString::fromStdString(mchat->getMsgText()));
				litterIems[i]->chat->alert();//��������˸
			}
			else if(litterIems[i]->isInited&& litterIems[i]->m_mbox)//��ʼ���˴��ڲ����е���
			{
				//�Ѵ��ڳ�ʼ���õ��ǲ���
				litterIems[i]->chat->recvShowMsg(QString::fromStdString(mchat->getMsgText()));
				litterIems[i]->m_msgBox->m->addMsg(QString::fromStdString(mchat->getMsgText()));
				
				
			}else if (litterIems[i]->isInited&&!litterIems[i]->m_mbox)//���ڳ�ʼ������û֪ͨ
			{
				//litterIems[i]->m_msgBox->m->addMsg(QString::fromStdString(mchat->getMsgText()));
			}

		}
		else if (buf[0]==0x77)//�������������ˢ�º��ѵ���Ϣ
		{
			MsgRefreshFriend* mrefresh = ptool->parse_refresh(buf_s);
			//Ȼ���ҵ�jknum��Ӧ��litterIem��ˢ�´���
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
		else if(buf[0]==0x75)//�������Ӻ��ѵ���Ϣ
		{
			MsgAddFriend *m_AddFriend = ptool->parse_add(buf_s);

			emit FriendBox(m_AddFriend->getPic(), m_AddFriend->getAdd_id());
			src_listName = m_AddFriend->getList_name();
			
		}
		else if(buf[0]==0x34)//����������û�����Ϣ
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
