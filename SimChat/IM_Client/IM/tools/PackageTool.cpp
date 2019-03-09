#include "PackageTool.h"
#include <string.h>
#include <winsock.h>



void PackageTools::packMsgLogin(char* msg,MsgLogin msglogin)//测试发现字符串java可以直接解析，但是其他变量不行
/*在login打包时JKNum用字符串发送*/
{
	writeHead(msg, msglogin);
	writeString(msg + 13, (char*)msglogin.getPwd().data(), 10);
}
//void PackageTools::packMsgAddFriend(char * msg, MsgAddFriend msg_add_friend)
//{
//	writeHead(msg, msg_add_friend);
//	writeString(msg + 13, (char*)msg_add_friend.getAdd_id().data(), 9);
//	writeString(msg + 22, (char*)msg_add_friend.getList_name().data(), 10);
//}
void PackageTools::packMsgAddFriendResp(char* msg, MsgAddFriendResp* msg_add_friend_resp)
{
	writeHead(msg, msg_add_friend_resp);
	char* tmsg=msg += 13;
	char t[1];
	t[0] = msg_add_friend_resp->getState();
	memcpy(tmsg, t, 1);
	tmsg += 1;
	writeInt(tmsg, msg_add_friend_resp->getAdd_id());
	writeString(tmsg, (char*)msg_add_friend_resp->getList_name().data(),10);
	tmsg += 10;
	
	writeInt(tmsg, msg_add_friend_resp->getAgreeId());
	writeString(tmsg, (char*)msg_add_friend_resp->getAgreeListName().data(), 10);
	//delete tmsg;
}



void PackageTools::packMsgChat(char* msg, MsgChat* msg_chat)
{
	writeHead(msg, msg_chat);
	writeString(msg + 13, (char*)msg_chat->getMsgText().data(),1024);
}

void PackageTools::writeHead(char* a, MsgHead msg_head)//注意网络字节序的转换
{
	int len[2];
	len[0] = msg_head.getTotalLen();
	int t[1];
	t[0] = htonl(len[0]);
	memcpy(a, t, 4);

	char type[2];
	type[0] = msg_head.getType();
	memcpy(a + 4, type, 1);
	int dest[2];
	dest[0] = htonl(msg_head.getDest());
	memcpy(a + 5, dest, 4);
	int src[2];
	src[0] = htonl(msg_head.getSrc());
	memcpy(a + 9, src, 4);
}

void PackageTools::writeHead(char* a, MsgHead* msg_head)//注意网络字节序的转换
{
	int len[2];
	len[0] = msg_head->getTotalLen();
	int t[1];
	t[0] = htonl(len[0]);
	memcpy(a, t, 4);

	char type[2];
	type[0] = msg_head->getType();
	memcpy(a + 4, type, 1);
	int dest[2];
	dest[0] = htonl(msg_head->getDest());
	memcpy(a + 5, dest, 4);
	int src[2];
	src[0] = htonl(msg_head->getSrc());
	memcpy(a + 9, src, 4);
}


void PackageTools::writeString(char* a, char* b,int len)
{
	if (strlen(b)>len)
	{
		printf("超长\n");
		return;
	}
	memcpy(a, b,len);
	int remain = len - strlen(b);
	while (remain>0)//补0
	{
		memcpy(a+len-remain, "\0",1);
		remain--;
	}
}
void PackageTools::writeInt(char*& a, int b)
{
	//TODO
	int t[1];
	t[0] = htonl(b);
	memcpy(a, t, 4);
	a += 4;
}
void PackageTools(char*& a)
{
	
}
void PackageTools::packMsgSearch(char* msg, MsgSearch* m_search)
{
	writeHead(msg, m_search);
	char* buf_s = msg+13;
	writeInt(buf_s, m_search->jkNum);
}
void PackageTools::packMsgAddFriend(char * msg, MsgAddFriend * msg_add_friend)
{
	writeHead(msg, msg_add_friend);
	char* buf_s = msg + 13;
	writeInt(buf_s, msg_add_friend->getAdd_id());
	writeString(buf_s, (char*)msg_add_friend->getList_name().data(), 10);
	buf_s += 10;

	writeInt(buf_s, msg_add_friend->getPic());
}
void PackageTools::packMsgReg(char* msg, MsgReg* mreg)
{
	writeHead(msg, mreg);
	char* msg_s=msg + 13;
	writeString(msg_s, (char*)mreg->getName().data(),10);
	msg_s += 10;
	writeString(msg_s, (char*)mreg->getPasswd().data(), 10);


}
