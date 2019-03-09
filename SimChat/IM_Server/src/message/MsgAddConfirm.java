package message;


import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgAddConfirm extends MsgHead {
    private int srcJknum;//目的地
    private int newJKNum;//新添加的人
    private int newPic;//新添加的人的头像
    private String newListname;
    private String newNickname;
    public int getSrcJknum() {
        return srcJknum;
    }

    public int getNewJKNum() {
        return newJKNum;
    }

    public int getNewPic() {
        return newPic;
    }

    public String getNewNickname() {
        return newNickname;
    }

    public void setSrcJknum(int srcJknum) {
        this.srcJknum = srcJknum;
    }

    public void setNewJKNum(int newJKNum) {
        this.newJKNum = newJKNum;
    }

    public void setNewPic(int newPic) {
        this.newPic = newPic;
    }

    public void setNewNickname(String newNickname) {
        this.newNickname = newNickname;
    }
    public void setNewListname(String NewListname){
        this.newListname=NewListname;
    }
    public String getNewListname(){
        return newListname;
    }

    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous = new ByteArrayOutputStream();
        DataOutputStream dous = new DataOutputStream(bous);
        packMessageHead(dous);
        dous.writeInt(srcJknum);
        dous.writeInt(newJKNum);
        dous.writeInt(newPic);
        writeString(dous, 10, newListname);
        writeString(dous,10,newNickname);
        dous.flush();
        byte[] data = bous.toByteArray();
        return data;
    }
}
