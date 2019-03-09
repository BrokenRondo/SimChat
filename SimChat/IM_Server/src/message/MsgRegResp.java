package message;

import dataBase.ServerJK;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgRegResp extends MsgHead {
    private byte state;
    private int jkNum;
    public byte getState() {
        return state;
    }

    public void setState(byte state) {
        this.state = state;
    }
    public MsgRegResp(){}

    public MsgRegResp(int jkDest,byte state){
        setTotalLen(14);
        setType((byte)0x11);
        setDest(jkDest);
        setSrc(ServerJK.ServerJK);
        setState(state);
    }
    public int getJkNum(){
        return jkNum;
    }
    public void setJkNum(int jkNum){
        this.jkNum=jkNum;
    }

    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous=new ByteArrayOutputStream();
        DataOutputStream dous=new DataOutputStream(bous);
        packMessageHead(dous);
        dous.write(getState());
        dous.writeInt(getJkNum());
        dous.flush();
        byte[] data=bous.toByteArray();
        return data;
    }
}
