package dataBase;

import java.sql.ResultSet;
import java.sql.SQLException;

public class UserInfo {
	/*
	 * 用户基本信息
	 */

	private int JKNum;// 保存该用户的JK号
	private String nickName;// 保存该用户的昵称
	private int avatar;

	UserInfo(ResultSet userResult) throws SQLException {
	    JKNum = userResult.getInt("user_id");
	    nickName = userResult.getString("nickname");
	    avatar = userResult.getInt("avatar");
    }

	/*
	 * 用户好友信息
	 */

	private byte groupCount;// 保存有多少组好友
	private String ListName[];// 保存每个分组的名称
	private byte[] bodyCount;// 每组有多少个人
	private int bodyNum[][];// 每个好友的JK号
	private int bodypic[][];//好友头像
	private String bodyName[][];// 每个好友的昵称

	public byte getCollectionCount() {
		return groupCount;
	}

	public void setGroupCount(byte listCount) {
		this.groupCount = listCount;
	}

	public String[] getListName() {
		return ListName;
	}

	public void setListName(String[] listName) {
		ListName = listName;
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

	public String[][] getBodyName() {
		return bodyName;
	}

	public void setBodyName(String[][] bodyName) {
		this.bodyName = bodyName;
	}

	public int getJKNum() {
		return JKNum;
	}

	public void setJKNum(int jKNum) {
		JKNum = jKNum;
	}

	public String getNickName() {
		return nickName;
	}

	public void setNickName(String nick) {
		nickName = nick;
	}

	public boolean equals(UserInfo compare) {
		if (compare.getJKNum() == JKNum/* && compare.getPassWord().equals(passWord)*/) {
			return true;
		}
		return false;
	}

	public int[][] getBodypic() {
		return bodypic;
	}

	public void setBodypic(int bodypic[][]) {
		this.bodypic = bodypic;
	}

	public int getAvatar() {
		return avatar;
	}

	public void setAvatar(int avatar) {
		this.avatar = avatar;
	}

}
