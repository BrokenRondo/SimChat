package message;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.OutputStream;

public class MsgAddFriend extends MsgHead {
    private int add_ID;
    private String list_name;
    private int src_pic;
    public int getAdd_ID() {
        return add_ID;
    }

    public void setAdd_ID(int add_ID) {
        this.add_ID = add_ID;
    }

    public String getList_name() {
        return list_name;
    }

    public void setList_name(String list_name) {
        this.list_name = list_name;
    }
    public int getSrc_pic(){
        return src_pic;
    }
    public void setSrc_pic(int pic){
        this.src_pic=pic;
    }
    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous = new ByteArrayOutputStream();
        DataOutputStream dous = new DataOutputStream(bous);
        packMessageHead(dous);
        dous.writeInt(getAdd_ID());
        writeString(dous,10,getList_name());
        dous.writeInt(getSrc_pic());
        dous.flush();
        byte[] data = bous.toByteArray();
        return data;
    }

    /*@Override
    public void send(OutputStream outputStream) throws IOException {
        ByteArrayOutputStream bous = new ByteArrayOutputStream();
        DataOutputStream dous = new DataOutputStream(bous);
        packMessageHead(dous);
        dous.writeInt(getAdd_ID());
        writeString(dous,10,getList_name());
        dous.writeInt(getSrc_pic());
    }*/
}
