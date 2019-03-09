package message;

import dataBase.ServerJK;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgLoginResp extends MsgHead {
    private byte state;

    public byte getState() {
        return state;
    }

    public void setState(byte state) {
        this.state = state;
    }

    public MsgLoginResp(){}

    public MsgLoginResp(byte check){
        setTotalLen(14);
        setType((byte)0x22);
        setDest(ServerJK.LoginJK);
        setSrc((ServerJK.ServerJK));
        setState(check);
    }

    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous=new ByteArrayOutputStream();
        DataOutputStream dous=new DataOutputStream(bous);
        packMessageHead(dous);
        dous.write(getState());
        dous.flush();
        byte[] data=bous.toByteArray();
        return data;
    }
}
