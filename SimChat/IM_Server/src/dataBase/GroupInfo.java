package dataBase;

import java.sql.*;
import java.util.List;

public class GroupInfo {
	private int ownerJK;
	private List<UserInfo>members;//�����еĳ�Ա
	private String name;
	private int id;//������
	
	/*��group���ݿ��ж�ȡ���ݣ�����Group����*/
	GroupInfo(ResultSet rs) throws SQLException{
		ownerJK=rs.getInt("user_id");
		name=rs.getString("name");
		id=rs.getInt("Group_id");
		
	}
	
	public List<UserInfo>getMembers() throws SQLException{
		if(members==null) {
			DBConnector conn=DBConnector.getInstance();
			UserModel usermodel=new UserModel(conn);
			members=usermodel.getUsersInGroup(id);
		}
		return members;
	}
	 public int getOwnerJK() {
	        return ownerJK;
	    }

	    public void setOwnerJK(int ownerJK) {
	        this.ownerJK = ownerJK;
	    }

	    public String getName() {
	        return name;
	    }

	    public void setName(String name) {
	        this.name = name;
	    }

	    public int getId() {
	        return id;
	    }

	    public void setId(int id) {
	        this.id = id;
	    }
}
