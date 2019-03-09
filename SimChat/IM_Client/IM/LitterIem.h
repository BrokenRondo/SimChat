#pragma once

#include <QWidget>
#include <QString>

#include <QMessageBox>
#include "SingleList.h"
#include "Chat.h"
#include "MyMessageBox.h"

namespace Ui { class LitterIem; };

class LitterIem : public QWidget
{
	Q_OBJECT

public:
	/**
	* @brief LitterIem
	* @param picPath 头像的文件路径
	* @param parent
	*/
	LitterIem(QString picPath,int state, QWidget *parent = Q_NULLPTR);
	LitterIem(int pic, int state, std::string name, int jkNum,std::string itemName, QWidget *parent = Q_NULLPTR);
	LitterIem(QString picPath, int state,SingleItem singleItem, QWidget *parent = Q_NULLPTR);
	~LitterIem();
	int getJkNum();
	void setJkNum(int jknum);
	char getState();
	void setState(char state);
	int getPic();
	void setPic(int pic);
	void setpicPath(QString picPath);
	std::string getNickName();
	void setNickName(std::string nickName);
	bool openOrNot();
	bool readOrNot();
	void setNotice();
	void clearNotice();
	void init();
	void showMsgBox(QString msg);
	bool hasMsgBox();
	void refreshPic(bool online);
	Chat* chat;
	bool m_mbox;//是否打开了右下角通知
	bool isInited;
	bool isOpen;
	bool notice;
	MyMessageBox *m_msgBox;

private:
	Ui::LitterIem *ui;
	int jkNum;
	char state;
	int pic;
	std::string nickName;
	//bool isOpen;
	//bool read;//是否有通知
	
	QString picPath;
private slots:
	void acceptClose();
	void msgboxclicked();
	void clearm_mbox();
	
protected:
	void mouseDoubleClickEvent(QMouseEvent* event) override;
};
