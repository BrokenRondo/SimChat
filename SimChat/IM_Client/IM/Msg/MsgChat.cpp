#include "MsgChat.h"

std::string MsgChat::getMsgText()
{
	return msgText;
}

void MsgChat::setMsgText(std::string msgText)
{
	this->msgText = msgText;
}

MsgChat::MsgChat(int from, int target, std::string text)
{
	int totalLen = 13;//ͷ�ĳ��ȣ���������Ҫ����text�ĳ���
	char msgType = 0x04;
	totalLen += text.length();
	setTotalLen(totalLen);
	setType(msgType);
	setDest(target);
	setSrc(from);
	setMsgText(text);
}

