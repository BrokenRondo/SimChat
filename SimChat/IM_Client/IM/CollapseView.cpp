#include "CollapseView.h"
#include "ui_CollapseView.h"
#include "osapi/Socket.h"
#include "socket_waitPackage.h"
#include "parseTool.h"
#include "CollapseViewItem.h"

extern OS_TcpSocket client_socket;
GroupList groupList;
CollapseView::CollapseView(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::CollapseView();
	ui->setupUi(this);
	w_layout = new QVBoxLayout(this);
	w_layout->setContentsMargins(0, 0, 0, 0);//设置边距为0
	w_layout->setSpacing(0);

	groupList = getGroupList();
	if (groupList.ownerName.empty())//如果没有解析到数据或者其他原因先随机初始化
	{
		w_layout->addWidget(new CollapseViewItem(QString::fromLocal8Bit("我的好友"), this));
		w_layout->addWidget(new CollapseViewItem(QString::fromLocal8Bit("那些年"), this));
		w_layout->addWidget(new CollapseViewItem(QString::fromLocal8Bit("陌生人"), this));
		w_layout ->addStretch(1); //如果不添加这个，CollapseViewItem的高度会太大
	}
	else//如果解析出数据
	{
		//根据有多少个分组列表设置
		for (int i=0;i<groupList.groupList.size();i++)
		{
			//对每个分组
			collapseviewItem = new CollapseViewItem(groupList.groupList[i], this);
			w_layout->addWidget(collapseviewItem);
			collapse_view_List.push_back(collapseviewItem);
			collapseViewItemCount += 1;
		}
		w_layout->addStretch(1);
	}

	ui->scrollAreaWidgetContents->setLayout(w_layout);
}

CollapseView::~CollapseView()
{
	delete ui;
}
GroupList CollapseView::getGroupList()
{
	char buf[2048];
	client_socket.Recv(buf, 4);//首先读取包长度
	int pack_len[1];
	memcpy(pack_len, buf, 4);
	pack_len[0] = ntohl(pack_len[0]) - 4;//减去用来表示长度的四位
	//然后再读取一定长度
	socket_waitPackage socket_wait;
	socket_wait.WaitBytes(client_socket, buf, pack_len[0], 0);
	parseTool parsetool;
	if (buf[0]!=0x03)
	{
		qDebug("无法解析数据包，随机生成好友列表\n");
		GroupList fail;
		fail.ownerName="";
		return fail;
	}
	char* buf_s = buf;//用来指向buf的地址，在读取时用来后移读取数据
	MsgGroupList group_list = parsetool.parse_group_list(buf_s, pack_len[0]);
	groupList = parsetool.parse_list(group_list);
	return groupList;
}
