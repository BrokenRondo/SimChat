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
	w_layout->setContentsMargins(0, 0, 0, 0);//���ñ߾�Ϊ0
	w_layout->setSpacing(0);

	groupList = getGroupList();
	if (groupList.ownerName.empty())//���û�н��������ݻ�������ԭ���������ʼ��
	{
		w_layout->addWidget(new CollapseViewItem(QString::fromLocal8Bit("�ҵĺ���"), this));
		w_layout->addWidget(new CollapseViewItem(QString::fromLocal8Bit("��Щ��"), this));
		w_layout->addWidget(new CollapseViewItem(QString::fromLocal8Bit("İ����"), this));
		w_layout ->addStretch(1); //�������������CollapseViewItem�ĸ߶Ȼ�̫��
	}
	else//�������������
	{
		//�����ж��ٸ������б�����
		for (int i=0;i<groupList.groupList.size();i++)
		{
			//��ÿ������
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
	client_socket.Recv(buf, 4);//���ȶ�ȡ������
	int pack_len[1];
	memcpy(pack_len, buf, 4);
	pack_len[0] = ntohl(pack_len[0]) - 4;//��ȥ������ʾ���ȵ���λ
	//Ȼ���ٶ�ȡһ������
	socket_waitPackage socket_wait;
	socket_wait.WaitBytes(client_socket, buf, pack_len[0], 0);
	parseTool parsetool;
	if (buf[0]!=0x03)
	{
		qDebug("�޷��������ݰ���������ɺ����б�\n");
		GroupList fail;
		fail.ownerName="";
		return fail;
	}
	char* buf_s = buf;//����ָ��buf�ĵ�ַ���ڶ�ȡʱ�������ƶ�ȡ����
	MsgGroupList group_list = parsetool.parse_group_list(buf_s, pack_len[0]);
	groupList = parsetool.parse_list(group_list);
	return groupList;
}
