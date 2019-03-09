package message;
import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgAddFriendResp extends MsgHead {
    private byte state;
    private int src_id;
    private String src_add_listName;
    private int agree_id;
    private String agree_listName;
    public  int getSrc_id( ){
        return src_id;
    }
    public void setSrc_id(int src_id){
        this.src_id=src_id;
    }
    public int getAgree_id(){
        return agree_id;
    }
    public void setAgree_id(int agree_id){
        this.agree_id=agree_id;
    }
    public String getSrc_add_listName(){
        return src_add_listName;
    }
    public void setSrc_add_listName(String src_add_listName){
        this.src_add_listName=src_add_listName;
    }
    public String getAgree_listName(){
        return  agree_listName;
    }
    public void setAgree_listName(String agree_listName){
        this.agree_listName=agree_listName;
    }
    public byte getState() {
        return state;
    }
    
    public void setState(byte state) {
        this.state = state;
    }
    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous = new ByteArrayOutputStream();
        DataOutputStream dous = new DataOutputStream(bous);
        packMessageHead(dous);
        dous.write(getState());
        dous.flush();
        byte[] data = bous.toByteArray();
        return data;
    }
}
