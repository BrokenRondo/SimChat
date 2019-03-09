package message;

import java.io.ByteArrayOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;

public class MsgReg extends MsgHead {
	private String Name;
	private String passwd;
	
	public String getName() {
		return Name;
	}
	
	public String getPasswd() {
		return passwd;
	}
	
	public void SetName(String name) {
		this.Name=name;
	}
	
	public void setPasswd(String passwd) {
		this.passwd=passwd;
	}

	@Override
	public byte[] packMessage() throws IOException {
		ByteArrayOutputStream bous = new ByteArrayOutputStream();
		DataOutputStream dous = new DataOutputStream(bous);
		packMessageHead(dous);
		writeString(dous, 10,getName());
		writeString(dous,10,getPasswd());
		dous.flush();
		return super.packMessage();
	}
	
}
