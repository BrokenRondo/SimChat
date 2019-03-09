package message;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgSearchResult extends MsgHead {

    private byte result;
    private int jkNum;//要查找的号码
    private int pic;
    private String name;
    public int getJkNum(){
        return jkNum;
    }
    public byte getResult(){
        return result;
    }
    public void setJkNum(int jkNum){
        this.jkNum=jkNum;
    }
    public void setResult(byte result){
        this.result=result;
    }
    public int getPic(){ return pic; }

    public void setPic(int pic) {
        this.pic = pic;
    }
    public String getName(){
        return name;
    }
    public void setName(String name){
        this.name=name;
    }

    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous = new ByteArrayOutputStream();
        DataOutputStream dous = new DataOutputStream(bous);
        packMessageHead(dous);
        dous.writeByte(getResult());
        dous.writeInt(getJkNum());
        dous.writeInt(getPic());
        writeString(dous,10,getName());
        dous.flush();
        byte[] data = bous.toByteArray();
        return data;
    }
}
