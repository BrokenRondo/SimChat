package message;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgLogin extends MsgHead{
    private String psw;

    public String getPsw() {
        return psw;
    }

    public void setPsw(String pwd) {
        this.psw = pwd;
    }

    @Override
    public byte[] packMessage() throws IOException {
        ByteArrayOutputStream bous=new ByteArrayOutputStream();
        DataOutputStream dous=new DataOutputStream(bous);
        packMessageHead(dous);
        writeString(dous,10,getPsw());
        dous.flush();
        return bous.toByteArray();
    }
}
