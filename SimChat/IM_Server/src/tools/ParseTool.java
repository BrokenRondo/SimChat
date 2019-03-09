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

    //���·��������жϴ���������Ϣ��Ҫ��ʲô
    public static MsgHead parseMsg(byte[] data) throws IOException {
        int totalLength = data.length + 4;//������λ������ʾ�����ȵ�int��ռ��λ��
        //�ֽ��������������ڴ��п���һ�����������������������ȡ������
        ByteArrayInputStream bins = new ByteArrayInputStream(data);
        DataInputStream dins = new DataInputStream(bins);
        byte msgtype = dins.readByte();
        int dest = dins.readInt();
        int src = dins.readInt();
        if (msgtype == 0x01) {//˵����ע�����Ϣ
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
        } else if (msgtype == 0x02) { // ����ǵ�½��Ϣ
            String pwd = ReadString(dins, 10);
            MsgLogin mli = new MsgLogin();
            mli.setTotalLen(totalLength);
            mli.setType(msgtype);
            mli.setDest(dest);
            mli.setSrc(src);
            mli.setPsw(pwd);
            return mli;
        } else if (msgtype == 0x22) { // ����ǵ�½������Ϣ
            byte state = dins.readByte();
            MsgLoginResp mlr = new MsgLoginResp();
            mlr.setTotalLen(totalLength);
            mlr.setType(msgtype);
            mlr.setDest(dest);
            mlr.setSrc(src);
            mlr.setState(state);
            return mlr;
        } else if (msgtype == 0x04) {//����Ƿ�����Ϣ
            MsgChat mc = new MsgChat();
            String msgText = ReadString(dins, totalLength - 13);//13��ͷ����С
            mc.setTotalLen(totalLength);
            mc.setType(msgtype);
            mc.setDest(dest);
            mc.setSrc(src);
            mc.setMsgText(msgText);
            return mc;
        } else if (msgtype == 0x05) { //��Ӻ���
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
        } else if (msgtype == 0x55) { //��Ӻ��ѻ�ִ
            MsgAddFriendResp mafr = new MsgAddFriendResp();
            byte state = dins.readByte();
            mafr.setTotalLen(totalLength);
            mafr.setType(msgtype);
            mafr.setDest(dest);
            mafr.setSrc(src);
            mafr.setState(state);
            return mafr;
        }else if (msgtype==0x03){//�����б�
            String UserName=ReadString(dins,10);//��ȡ�û���
            int pic=dins.readInt();//��ȡͷ��
            byte listCount=dins.readByte();//��ȡ���ѷ������
            String listName[]=new String[listCount];
            byte bodyCount[]=new byte[listCount];//ÿ�������ж��ٸ�����

            int bodyNum[][];//ÿ�����ѵĺ���
            bodyNum=new int[listCount][];//��һά�����Ƿ�������

            int bodyPic[][];
            bodyPic=new int[listCount][];

            String nikeName[][];
            nikeName=new String[listCount][];

            byte bodyState[][];
            bodyState=new byte[listCount][];

            for (int i=0;i<listCount;i++){
                listName[i]=ReadString(dins,10);
                bodyCount[i]=dins.readByte();
                bodyNum[i]=new int[bodyCount[i]];//���õڶ�ά���ȣ�ÿ��������Ѹ���
                bodyPic[i]=new int[bodyCount[i]];
                nikeName[i]=new String[bodyCount[i]];
                bodyState[i]=new byte[bodyCount[i]];

                for (int j=0;j<bodyCount[i];j++){//����������ÿ����Ա
                    bodyNum[i][j]=dins.readInt();
                    bodyPic[i][j]=dins .readInt();
                    nikeName[i][j]=ReadString(dins,10);
                    bodyState[i][j]=dins.readByte();
                    System.out.println(bodyNum[i][j]+" "+bodyPic[i][j]+" "+nikeName[i][j]+" "+bodyState[i][j]);
                }
            }

            //��ȡ������д��class��
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
                System.out.println("�ܾ���Ӻ��ѵ�����");
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
        }else if(msgtype==0x33){//���������
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
