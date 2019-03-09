package message;

import dataBase.ServerJK;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgRefreshFriend extends MsgHead{
    private int jkNum;
    private byte online;
    int getJKNum(){
        return jkNum;
    }
    void setJkNum(int jknum) {
        this.jkNum = jknum;
    }
    byte getOnline(){
        return online;
    }
    void setOnline(byte online  ){
        this.online=online;
    }
    public MsgRefreshFriend(int jkNum,int dest,byte online){
        setJkNum(jkNum);
        setTotalLen(13+4+1);//4字节jknum,1字节online
        setType((byte)0x77);
        setSrc(ServerJK.ServerJK);
        setDest(dest);
        setOnline(online);
    }

    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous=new ByteArrayOutputStream();
        DataOutputStream dous=new DataOutputStream(bous);
        packMessageHead(dous);
        dous.writeInt(jkNum);
        dous.write(online);
        dous.flush();
        byte[] data=bous.toByteArray();
        return data;
    }
}
