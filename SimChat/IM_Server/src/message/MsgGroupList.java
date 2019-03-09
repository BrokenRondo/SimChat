package message;

import dataBase.ServerJK;
import dataBase.ThreadMap;
import dataBase.UserInfo;
import tools.ThreadTool;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgGroupList extends MsgHead {
    private String UserName;
    private int pic;
    private byte listCount;
    private String[] listName;
    private byte[] bodyCount;
    private int[][] bodyNum;
    private int[][] bodyPic;
    private String[][] nikeName;
    private byte[][] bodyState;

    public MsgGroupList() {
    }

    public MsgGroupList(UserInfo user) {
        setType((byte) 0x03);
        setDest(user.getJKNum());
        setSrc(ServerJK.ServerJK);
        setUserName(user.getNickName());
        setPic(user.getAvatar());
        setListCount(user.getCollectionCount());
        setListName(user.getListName());
        setBodyCount(user.getBodyCount());
        setBodyNum(user.getBodyNum());
        setBodyPic(user.getBodypic());
        setNikeName(user.getBodyName());
        int len = 13;//头长度
        len += 10;//userName
        len += 4;//pic
        len += 1;//listCount
        len += (10 * listCount);
        len += listCount;    //bodyCount
        bodyState = new byte[listCount][];
        for (int i = 0; i < listCount; i++) {
            len += bodyCount[i] * 19;
            bodyState[i] = new byte[bodyCount[i]];
        }
        //检查好友是否在线：去线程数据库查找是否有同样JK的线程
        for (int i = 0; i < listCount; i++) {
            for (int j = 0; j < bodyCount[i]; j++) {
                if (ThreadMap.threadMap.containsKey(String.valueOf(bodyNum[i][j]))) {
                    bodyState[i][j] = 1;
                } else {
                    bodyState[i][j] = 0;
                }
            }
        }
        setTotalLen(len);
    }

    public String getUserName() {
        return UserName;
    }

    public void setUserName(String userName) {
        UserName = userName;
    }

    public int getPic() {
        return pic;
    }

    public void setPic(int pic) {
        this.pic = pic;
    }

    public byte getListCount() {
        return listCount;
    }

    public void setListCount(byte listCount) {
        this.listCount = listCount;
    }

    public String[] getListName() {
        return listName;
    }

    public void setListName(String[] listName) {
        this.listName = listName;
    }

    public byte[] getBodyCount() {
        return bodyCount;
    }

    public void setBodyCount(byte[] bodyCount) {
        this.bodyCount = bodyCount;
    }

    public int[][] getBodyNum() {
        return bodyNum;
    }

    public void setBodyNum(int[][] bodyNum) {
        this.bodyNum = bodyNum;
    }

    public String[][] getNikeName() {
        return nikeName;
    }

    public void setNikeName(String[][] nikeName) {
        this.nikeName = nikeName;
    }

    public byte[][] getBodyState() {
        return bodyState;
    }

    public void setBodyState(byte[][] bodyState) {
        this.bodyState = bodyState;
    }

    public int[][] getBodyPic() {
        return bodyPic;
    }

    public void setBodyPic(int bodyPic[][]) {
        this.bodyPic = bodyPic;
    }

    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous = new ByteArrayOutputStream();
        DataOutputStream dous = new DataOutputStream(bous);
        packMessageHead(dous);
        String userName = getUserName();
        int pic = getPic();
        byte listCount = getListCount();
        String[] listName = getListName();
        byte[] bodyCount = getBodyCount();
        int[][] bodyNum = getBodyNum();
        int bodyPic[][] = getBodyPic();
        String[][] nikeName = getNikeName();
        byte[][] bodyState = getBodyState();

        //将信息写入流中
        writeString(dous, 10, userName);
        dous.writeInt(pic);
        dous.write(listCount);//分组个数
        for (int i = 0; i < listCount; i++) {
            writeString(dous, 10, listName[i]);
            dous.write(bodyCount[i]);//每一组里有多少好友
            for (int j = 0; j < bodyCount[i]; j++) {//每个分组里的每个好友
                dous.writeInt(bodyNum[i][j]);
                dous.writeInt(bodyPic[i][j]);
                writeString(dous, 10, nikeName[i][j]);
                dous.write(bodyState[i][j]);
            }
        }
        dous.flush();
        byte[] data = bous.toByteArray();
        return data;
    }
}
