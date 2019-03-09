package dataBase;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class GroupModel {

	private DBConnector connection;
	public GroupModel(DBConnector con) {
		this.connection=con;
	}
	
	/*根据用户的jk号码获得分组的list*/
	public List<GroupInfo>getGroupByJK(int jk) throws SQLException{
		ResultSet rs=connection.query("SELECT * FROM collection where user_id="+jk);
		ArrayList<GroupInfo>res =new ArrayList<>();
		while(rs.next()) {
			res.add(new GroupInfo(rs));
		}

		rs.close();
		return res;
	}
	/*将用户添加到分组*/
	public int addUserToGroup(int jk,int groupID) throws Exception {
		return connection.update(String.format("INSERT INTO group_entry (user_id,group_id)values (%d,%d) ", jk,groupID));
	}

	public GroupInfo getGroup(int id) throws SQLException {
		String sql=String.format("SELECT * FROM group where group_id=%d", id);
		ResultSet rs=connection.query(sql);
		if(!rs.next()) return null;
		GroupInfo result=new GroupInfo(rs);
		rs.close();
		return result;
	}
	/*判断用户是否在某个分组里*/
	public boolean isUserInGroup(int userJK,int GroupID) throws SQLException {
		ResultSet rs=connection.query(String.format("SELECT * FROM Group_entry where user_id=%d AND collection_id=%d", userJK, GroupID));
		return rs.next();
	}
	/*用分组名字和分组所有者查找分组*/
	public GroupInfo getGroupByNameAndOwner(String name,int jk) throws SQLException {
	    String sql=String.format("SELECT * FROM collection where user_id=%d AND name='%s'", jk, name);
	    ResultSet rs=connection.query(sql);
	    if(!rs.next()){
	        return null;
        }
        GroupInfo result=new GroupInfo(rs);
	    rs.close();
	    return result;
    }
    public GroupInfo createGroup(int jk,String groupName) throws SQLException {
		String sql=String.format("INSERT INTO collection (name, user_id) VALUES ('%s', %d)", groupName, jk);
		int id=connection.InstertandGetKey(sql);
		return getGroup(id);
	}
	
}
