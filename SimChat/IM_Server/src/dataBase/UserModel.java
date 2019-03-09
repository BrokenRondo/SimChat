package dataBase;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class UserModel {//和user有关的方法都写在这里
    DBConnector con;

    public UserModel(DBConnector conn) {//构造函数，需要连接数据库的DBConnector的对象
        this.con = conn;
    }

    //创建用户
    public UserInfo createUser(int jkNum, String name, String passwd, int avatar) throws SQLException {
        String driver = "com.mysql.jdbc.Driver";
        String url = "jdbc:mysql://localhost:3306/IMServer";
        String user = "root";
        String password = "521520";
        String srcname = "";
        String newName = "";
        try {
            Class.forName(driver);
        } catch (ClassNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        Connection conn1=DriverManager.getConnection(url, user, passwd);
        String sql = String.format("INSERT INTO users (user_id,name,password,avatar) VALUES (%d,%s,%s,%d)", jkNum, name, passwd, avatar);
        
        int[] ran = new int[8];
        int min = 1000000;
        int max = 999999999;

        
        int t = 0;
       
        for (int i = 0; ; i++) {
            ran[t] = new Random().nextInt(max - min) + min;
            try {
                if (!conn1.isClosed()) {
                    System.out.println("成功连接到数据库");
                }
                Statement stmt = conn1.createStatement();
                ResultSet rs = stmt.executeQuery(String.format("select * from collection where group_id=%d", ran));
                if (!rs.next()) {
                    t++;
                    if (t==10){
                        conn1.close();
                        break;
                    }
                }

            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        int res = con.InstertandGetKey(sql);

        //return getUserByJK(res);
        return null;
    }

    //删除用户
    public int removeUser(int jk) throws SQLException {
        String sql = String.format("DELETE FROM users WHERE user_id=%d", jk);
        int res = con.update(sql);
        return res;
    }

    public List<UserInfo> getUsersInGroup(int groupID) throws SQLException {
        ResultSet rs = con.query("SELECT * FROM users WHERE user_id IN (SELECT user_id FROM group_entry WHERE group_id = " + groupID + ")");
        ArrayList<UserInfo> res = new ArrayList<>();
        while (rs.next()) {
            res.add(new UserInfo(rs));
        }
        rs.close();
        return res;
    }

    public UserInfo getUserByJK(int JK) throws SQLException {
        ResultSet rs = con.query("SELECT * FROM users where user_id=" + JK);
        if (!rs.next()) return null;
        UserInfo user = new UserInfo(rs);

        //获取好友列表
        GroupModel groupModel = new GroupModel(con);
        List<GroupInfo> groupInfos = groupModel.getGroupByJK(JK);
        GroupInfo groupInfo;
        List<UserInfo> memberlist;
        UserInfo member;

        int groupCount = groupInfos.size();
        int memberCount = 0;
        user.setGroupCount((byte) groupCount);
        String[] ListName = new String[groupCount];
        byte[] bodyCount = new byte[groupCount];
        int bodyNum[][] = new int[groupCount][];//每个好友的jk号码
        int bodypic[][] = new int[groupCount][];
        String bodyName[][] = new String[groupCount][];

        for (int j = 0; j < groupInfos.size(); j++) {
            try {
                groupInfo = groupInfos.get(j);
                ListName[j] = groupInfo.getName();
                memberlist = groupInfo.getMembers();
                memberCount = memberlist.size();
                bodyCount[j] = (byte) memberCount;//bodyCount 每组多少人
                bodyNum[j] = new int[memberCount];//每个组好友的JK号
                bodyName[j] = new String[memberCount];
                bodypic[j] = new int[memberCount];

                for (int i = 0; i < memberlist.size(); i++) {
                    member = memberlist.get(i);
                    bodyNum[j][i] = member.getJKNum();
                    bodyName[j][i] = member.getNickName();
                    bodypic[j][i] = member.getAvatar();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        //设置本用户信息
        user.setBodyName(bodyName);
        user.setListName(ListName);
        user.setBodyCount(bodyCount);
        user.setBodyNum(bodyNum);
        user.setBodypic(bodypic);
        rs.close();
        return user;
    }

    /*认证用户*/
    public boolean userAuthorization(int jk, String passwd) throws SQLException {
        ResultSet rs = con.query(String.format("SELECT * FROM users WHERE user_id=%d AND password='%s'", jk, passwd));
        if (!rs.next()) return false;
        rs.close();
        return true;
    }

    /*判断是不是好友*/
    public boolean isFriendsOfUser(int target, int jk) throws SQLException {
        String sql = String.format(
                "SELECT\n" +
                        "	*\n" +
                        "FROM\n" +
                        "	users\n" +
                        "WHERE\n" +
                        "	user_id = %d\n" +
                        "AND users.user_id IN (\n" +
                        "	SELECT\n" +
                        "		user_id\n" +
                        "	FROM\n" +
                        "		group_entry\n" +
                        "	WHERE\n" +
                        "		group_id IN (\n" +
                        "			SELECT\n" +
                        "				group_id\n" +
                        "			FROM\n" +
                        "				collection\n" +
                        "			WHERE\n" +
                        "				user_id = %d\n" +
                        "		)\n" +
                        ")", target, jk);
        ResultSet rs = con.query(sql);
        return rs.next();
    }

    //添加好友
    public int addFriend(int addJK, int ownJK, String listName) throws Exception {
        //首先检查有没有这个号码
        UserInfo dest = getUserByJK(addJK);
        if (dest == null) {
            return 0;//不存在
        }
        GroupModel groupModel = new GroupModel(con);
        GroupInfo groupInfo = groupModel.getGroupByNameAndOwner(listName, addJK);
        if (groupInfo == null) {
            groupInfo = groupModel.createGroup(ownJK, listName);
        } else if (isFriendsOfUser(ownJK, addJK)) {
            return 2;//已经是好友
        }
        groupModel.addUserToGroup(ownJK, groupInfo.getId());
        return 1;//添加好友在分组中
    }

}
