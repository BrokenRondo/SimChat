#include "parseTool.h"
#include "Msg_H.h"
#include <winsock2.h>
#include "MsgRefreshFriend.h"
#include "MsgSearchResult.h"
#include "MsgAddFriendConfirm.h"

/*传的参数是指针本身，调用本函数前需要保留原缓冲区的数组，然后传入指向数组第N个元素的指针*/
std::string parseTool::readString(char*& buf, int len)
{
	char* text = new char[2048];
	memset(text, 0, 2048);
	memcpy(text, buf, len);//记得字符串结尾要0
	std::string message = text;
	buf += len;
	delete[] text;
	return message;

}
int parseTool::readInt(char*& buf)
{
	int a[1] = { 0 };
	memcpy(a, buf, 4);
	buf += 4;
	return a[0];
}
char parseTool::readChar(char*& buf)
{
	char a[1] = { 0 };
	memcpy(a, buf, 1);
	buf += 1;
	return a[0];
}
MsgLoginResp parseTool::parse_msg_login_resp(char*& buf,int len)
{
	int totalLen = len + 4;//之前已经读取四个字节的长度信息
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));
	
	char state = readChar(buf);
	MsgLoginResp mlr;
	mlr.setTotalLen(totalLen);
	mlr.setType(msgType);
	mlr.setDest(dest);
	mlr.setSrc(src);
	mlr.setState(state);
	return mlr;
	
}
MsgGroupList parseTool::parse_group_list(char*& buf,int len)
{
	//首先读取数据头
	int totalLen = len + 4;
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));

	string UserName = readString(buf, 10);
	int pic = ntohl(readInt(buf));
	char listCount = readChar(buf);
	MsgGroupList mgl;
	mgl.setTotalLen(totalLen);
	mgl.setType(msgType);
	mgl.setDest(dest);
	mgl.setSrc(src);

	mgl.listName.resize(listCount);
	mgl.bodyCount.resize(listCount);
	vector<int> bodyNum1; 
	
	vector<int> bodyPic1;
	
	vector<string>nikeName1;
	
	vector<char>bodyState1;
	

	for (int i = 0; i < listCount; i++)
	{
		mgl.listName[i] = readString(buf, 10);
		mgl.bodyCount[i] = readChar(buf);
		bodyNum1.resize(mgl.bodyCount[i]);
		bodyPic1.resize(mgl.bodyCount[i]);
		nikeName1.resize(mgl.bodyCount[i]);
		bodyState1.resize(mgl.bodyCount[i]);
		for (int j=0;j<mgl.bodyCount[i];j++)
		{
			bodyNum1[j] = ntohl(readInt(buf));
			bodyPic1[j] = ntohl(readInt(buf));
			nikeName1[j] = readString(buf, 10);
			bodyState1[j] = readChar(buf);
		}
		mgl.bodyNum.push_back(bodyNum1);
		mgl.bodyPic.push_back(bodyPic1);
		mgl.nikeName.push_back(nikeName1);
		mgl.bodyState.push_back(bodyState1);
		
	}
	mgl.pic = pic;
	mgl.userName = UserName;
	mgl.listCount = listCount;
	return mgl;
}
GroupList parseTool::parse_list(MsgGroupList group_list)
{
	SingleList single_list;
	SingleItem single_item;
	GroupList groupList;
	string userName = group_list.userName;
	for (int i=0;i<group_list.listCount;i++)//对每一个列表
	{
		single_list.listName = group_list.listName[i];
		single_list.bodyCount = group_list.bodyCount[i];
		int online = 0;
		for (int j=0;j<group_list.bodyCount[i];j++)//对每一个好友
		{
			single_item.jkNum = group_list.bodyNum[i][j];
			single_item.bodyPic = group_list.bodyPic[i][j];
			single_item.nickName = group_list.nikeName[i][j];
			single_item.bodyState = group_list.bodyState[i][j];
			single_list.items.push_back(single_item);
			if (single_item.bodyState==1)
			{
				online++;
			}
		}
		single_list.bodyCount = single_list.items.size();
		single_list.online = online;
		single_list.offline = single_list.bodyCount - online;
		groupList.groupList.push_back(single_list);
	}
	groupList.ownerName = userName;
	return groupList;
}
MsgChat* parseTool::parse_chat(char*& buf, int len)
{
	int totalLen = len + 4;
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));
	MsgChat *mchat=new MsgChat();
	mchat->setType(msgType);
	mchat->setTotalLen(totalLen);
	mchat->setDest(dest);
	mchat->setSrc(src);
	mchat->setMsgText(readString(buf, totalLen-13));
	return mchat;
}
MsgRefreshFriend* parseTool::parse_refresh(char*& buf)
{
	//int totalLen = len + 4;
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));
	int jknum = ntohl(readInt(buf));
	char online = readChar(buf);
	MsgRefreshFriend* mrefresh = new MsgRefreshFriend(jknum, online);
	return mrefresh;
}
MsgAddFriend* parseTool::parse_add(char*& buf)
{
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));
	int jknum = ntohl(readInt(buf));
	//int srcid = ntohl(readInt(buf));
	std::string src_list_name = readString(buf, 10);
	int pic = ntohl(readInt(buf));
	MsgAddFriend* mAFriend = new MsgAddFriend();
	mAFriend->setAdd_id(jknum);
	mAFriend->setlist_name(src_list_name);
	mAFriend->setPic(pic);
	return mAFriend;
}
MsgSearchResult* parseTool::parse_m_result(char*& buf)
{
	MsgSearchResult* m_search = new MsgSearchResult();
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));
	char result = readChar(buf);
	if (result==0x00)
	{
		m_search->result = result;
		return m_search;
	}
	int jkNum =ntohl(readInt(buf));
	int pic = ntohl(readInt(buf));
	std::string name = readString(buf, 10);
	m_search->result = result;
	m_search->nickname = name;
	m_search->jkNum = jkNum;
	m_search->pic = pic;
	return m_search;
}

MsgAddFriendConfirm* parseTool::parse_Confirm(char*& buf)
{
	MsgAddFriendConfirm* mConfirm = new MsgAddFriendConfirm();
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));
	int srcJKNum = ntohl(readInt(buf));
	int newJKNum = ntohl(readInt(buf));
	int newPic = ntohl(readInt(buf));
	std::string newListName = readString(buf, 10);
	std::string newNickName = readString(buf, 10);
	mConfirm->srcJKNum = srcJKNum;
	mConfirm->newJKNum = newJKNum;
	mConfirm->newPic = newPic;
	mConfirm->newNickName = newNickName;
	mConfirm->newListName = newListName;
	return mConfirm;
}
MsgRegResp* parseTool::parse_RegResp(char*& buf)
{
	MsgRegResp *mRegResp = new MsgRegResp();
	char msgType = readChar(buf);
	int dest = ntohl(readInt(buf));//转换网络字节序到主机字节序
	int src = ntohl(readInt(buf));
	mRegResp->state = readChar(buf);
	mRegResp->JKNum = ntohl(readInt(buf));
	return mRegResp;
}
