package tools;

import java.io.ByteArrayInputStream;
import java.io.DataInputStream;
import java.io.IOException;


import dataBase.ServerJK;
import message.*;

public class ParseTool {
    private static String ReadString(DataInputStream dis, int len) throws IOException {
        byte[] data = new byte[len];
        dis.readFully(data);
        return new String(data).trim();
    }

    //以下方法用于判断传过来的信息需要做什么
    public static MsgHead parseMsg(byte[] data) throws IOException {
        int totalLength = data.length + 4;//加上四位用来表示包长度的int所占的位数
        //字节数组输入流在内存中开辟一个缓冲区用来存放输入流读取的数据
        ByteArrayInputStream bins = new ByteArrayInputStream(data);
        DataInputStream dins = new DataInputStream(bins);
        byte msgtype = dins.readByte();
        int dest = dins.readInt();
        int src = dins.readInt();
        if (msgtype == 0x01) {//说明是注册的信息
            String name = ReadString(dins, 10);
            String passwd = ReadString(dins, 10);
            MsgReg mr = new MsgReg();
            mr.setTotalLen(totalLength);
            mr.setType(msgtype);
            mr.setDest(dest);
            mr.SetName(name);
            mr.setPasswd(passwd);
            return mr;
        } else if (msgtype == 0x11) {
            byte state = dins.readByte();
            MsgRegResp mrr = new MsgRegResp();
            mrr.setTotalLen(totalLength);
            mrr.setType(msgtype);
            mrr.setDest(dest);
            mrr.setSrc(src);
            mrr.setState(state);
            return mrr;
        } else if (msgtype == 0x02) { // 如果是登陆信息
            String pwd = ReadString(dins, 10);
            MsgLogin mli = new MsgLogin();
            mli.setTotalLen(totalLength);
            mli.setType(msgtype);
            mli.setDest(dest);
            mli.setSrc(src);
            mli.setPsw(pwd);
            return mli;
        } else if (msgtype == 0x22) { // 如果是登陆返回信息
            byte state = dins.readByte();
            MsgLoginResp mlr = new MsgLoginResp();
            mlr.setTotalLen(totalLength);
            mlr.setType(msgtype);
            mlr.setDest(dest);
            mlr.setSrc(src);
            mlr.setState(state);
            return mlr;
        } else if (msgtype == 0x04) {//如果是发送消息
            MsgChat mc = new MsgChat();
            String msgText = ReadString(dins, totalLength - 13);//13是头部大小
            mc.setTotalLen(totalLength);
            mc.setType(msgtype);
            mc.setDest(dest);
            mc.setSrc(src);
            mc.setMsgText(msgText);
            return mc;
        } else if (msgtype == 0x05) { //添加好友
            MsgAddFriend maf = new MsgAddFriend();
            int add_id = dins.readInt();
            String list_name = ReadString(dins, totalLength - 17);
            maf.setTotalLen(totalLength);
            maf.setType(msgtype);
            maf.setDest(dest);
            maf.setSrc(src);
            maf.setAdd_ID(add_id);
            maf.setList_name(list_name);
            return maf;
        } else if (msgtype == 0x55) { //添加好友回执
            MsgAddFriendResp mafr = new MsgAddFriendResp();
            byte state = dins.readByte();
            mafr.setTotalLen(totalLength);
            mafr.setType(msgtype);
            mafr.setDest(dest);
            mafr.setSrc(src);
            mafr.setState(state);
            return mafr;
        }else if (msgtype==0x03){//好友列表
            String UserName=ReadString(dins,10);//读取用户名
            int pic=dins.readInt();//读取头像
            byte listCount=dins.readByte();//读取好友分组个数
            String listName[]=new String[listCount];
            byte bodyCount[]=new byte[listCount];//每个分组有多少个好友

            int bodyNum[][];//每个好友的号码
            bodyNum=new int[listCount][];//第一维长度是分组数量

            int bodyPic[][];
            bodyPic=new int[listCount][];

            String nikeName[][];
            nikeName=new String[listCount][];

            byte bodyState[][];
            bodyState=new byte[listCount][];

            for (int i=0;i<listCount;i++){
                listName[i]=ReadString(dins,10);
                bodyCount[i]=dins.readByte();
                bodyNum[i]=new int[bodyCount[i]];//设置第二维长度，每个分组好友个数
                bodyPic[i]=new int[bodyCount[i]];
                nikeName[i]=new String[bodyCount[i]];
                bodyState[i]=new byte[bodyCount[i]];

                for (int j=0;j<bodyCount[i];j++){//对这个分组的每个成员
                    bodyNum[i][j]=dins.readInt();
                    bodyPic[i][j]=dins .readInt();
                    nikeName[i][j]=ReadString(dins,10);
                    bodyState[i][j]=dins.readByte();
                    System.out.println(bodyNum[i][j]+" "+bodyPic[i][j]+" "+nikeName[i][j]+" "+bodyState[i][j]);
                }
            }

            //读取结束，写入class中
            MsgGroupList msgGroupList=new MsgGroupList();
            msgGroupList.setUserName(UserName);
            msgGroupList.setPic(pic);
            msgGroupList.setTotalLen(totalLength);
            msgGroupList.setType(msgtype);
            msgGroupList.setDest(dest);
            msgGroupList.setSrc(src);
            msgGroupList.setListCount(listCount);
            msgGroupList.setListName(listName);
            msgGroupList.setBodyCount(bodyCount);
            msgGroupList.setBodyPic(bodyPic);
            msgGroupList.setNikeName(nikeName);
            msgGroupList.setBodyState(bodyState);
            return  msgGroupList;
        }else if (msgtype==0x44)
        {
            MsgAddFriendResp mar=new MsgAddFriendResp();
            byte state=dins.readByte();
            if (state==0x00){
                System.out.println("拒绝添加好友的请求");
                return null;
            }
            int Add_id=dins.readInt();
            String src_listName=ReadString(dins,10);
            int agree_id=dins.readInt();
            String Agree_listName=ReadString(dins,10);
            mar.setType(msgtype);
            mar.setTotalLen(42);
            mar.setSrc(src);
            mar.setDest(dest);
            mar.setState(state);
            mar.setAgree_id(agree_id);
            mar.setAgree_listName(Agree_listName);
            mar.setSrc_add_listName(src_listName);
            mar.setSrc_id(Add_id);
            return mar;
        }else if(msgtype==0x33){//如果是搜索
            MsgSearch msear=new MsgSearch();
            msear.setTotalLen(32);
            msear.setDest(ServerJK.LoginJK);
            msear.setSrc(ServerJK.ServerJK);
            msear.setType(msgtype);
            int jkNum=dins.readInt();
            msear.setJkNum(jkNum);
            return msear;

        }else if(msgtype==0x24){
            MsgAddFriend madd=new MsgAddFriend();
            madd.setTotalLen(31);
            madd.setSrc(src);
            madd.setDest(dest);
            madd.setType((byte)0x24);
            madd.setAdd_ID(dins.readInt());
            madd.setList_name(ReadString(dins,10));
            int srcPic=dins.readInt();
            madd.setSrc_pic(srcPic);
            return madd;
            
        }


        return null;
    }
}
