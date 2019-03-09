package server;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.sql.*;
import java.util.Random;

import dataBase.*;
import message.*;
import tools.ChatTool;
import tools.ParseTool;
import tools.ThreadTool;


public class server_thread extends Thread {
    private Socket client;
    private int userID;
    private OutputStream ous;
    private InputStream ins;
    private boolean isOnline = false;
    private InputStreamReader isr = null;
    private OutputStreamWriter osr = null;
    private int UserJK;
    BufferedReader br = null;

    public server_thread(Socket client) {
        this.client = client;
    }

    public int getUserJK() {
        return UserJK;
    }

    public void run() {
        //重写run函数，实现循环执行的功能
        //首先实现登陆的功能
        while (!isOnline) {//如果还没有登陆就执行登陆程序
            try {
                processLogin();
            } catch (IOException e) {

                System.out.println(client.getRemoteSocketAddress() + "已断开");
                ThreadTool.DelThread(UserJK);
                isOnline = false;
                try {
                    broadcastState(false);
                } catch (SQLException e1) {
                    e1.printStackTrace();
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
                try {
                    client.close();
                } catch (IOException el) {
                    el.printStackTrace();
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        while (isOnline) {
            try {
                processChat();
            } catch (Exception e) {
                //客户端掉线
                System.out.println(client.getRemoteSocketAddress() + "已断开");
                ThreadTool.DelThread(UserJK);
                isOnline = false;
                try {
                    broadcastState(false);
                } catch (SQLException e1) {
                    e1.printStackTrace();
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
                try {
                    client.close();
                } catch (IOException el) {
                    el.printStackTrace();
                }
            } 
        }
    }

    private void processLogin() throws IOException, SQLException {
        //需要连接到数据库，在DBConnector中写了连接数据库的方法，在这里实例化
        DBConnector conn = DBConnector.getInstance();
        UserModel model = new UserModel(conn);
        ins = client.getInputStream();
        ous = client.getOutputStream();
        //连接到数据库以后判断客户端发送过来的请求类型


        DataInputStream dis = new DataInputStream(ins);

        MsgHead msg = MsgHead.ReadFromStream(dis);//如果是注册信息，返回一个MsgReg，其他类似
        //根据不同的 消息类别进行不同的处理（强转成子类？）
        if (msg.getType() == 0x01) {
            MsgReg mr = (MsgReg) msg;
            //接下来要注册用户，需要连接数据库
            //随机生成7到9位数号码
            int min = 1000000;
            int max = 999999999;
            int ran;
            ran = new Random().nextInt(max - min) + min;
            String driver = "com.mysql.jdbc.Driver";
            String url = "jdbc:mysql://localhost:3306/imserver";
            String user = "root";
            String passwd = "521520";
            String srcname = "";
            String newName = "";
            try {
                Class.forName(driver);
            } catch (ClassNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
            Connection conn1 = DriverManager.getConnection(url, user, passwd);
            for (int i = 0; ; i++) {
                try {
                    
                    if (!conn1.isClosed()) {
                        System.out.println("成功连接到数据库");
                    }
                    Statement stmt = conn1.createStatement();
                    ResultSet rs = stmt.executeQuery(String.format("select * from users where user_id=%d", ran));
                    if (!rs.next()) break;
                   
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            //model.createUser(ran,mr.getName(), mr.getPasswd(), 1);
           
            String sql = String.format("INSERT INTO users (user_id,nickname,password,avatar) VALUES (%d,'%s',%s,%d)", ran, mr.getName(), mr.getPasswd(), 1);
            Statement stmt = conn1.createStatement();
            stmt.executeUpdate(sql);
            int[] ranDon = new int[8];
            int t = 0;

            for (int i = 0; ; i++) {
                ranDon[t] = new Random().nextInt(max - min) + min;
                try {
                    if (!conn1.isClosed()) {
                        //System.out.println("成功连接到数据库");
                    }
                    stmt = conn1.createStatement();
                    ResultSet rs = stmt.executeQuery(String.format("select * from collection where group_id=%d", ran));
                    if (!rs.next()) {
                        t++;
                        if (t==8){
                            
                            break;
                        }
                    }

                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
            conn1.close();
           // int res = con.InstertandGetKey(sql);
            int jkNum = ran;

            /*注册完后返回信息*/
            byte state = 1;
            MsgRegResp msgRegResp = new MsgRegResp(jkNum, state);
            msgRegResp.setTotalLen(18);
            msgRegResp.setState(state);
            msgRegResp.setSrc(111112222);
            msgRegResp.setDest(222221111);
            msgRegResp.setType((byte)0x06);
            msgRegResp.setJkNum(jkNum);
            msgRegResp.send(ous);
        }
        if (msg.getType() == 0x02) {
            MsgLogin ml = (MsgLogin) msg;
            byte check;//用来存放是否通过验证的信息
            if (ThreadMap.threadMap.containsKey(String.valueOf(ml.getSrc()))) {
                check = 2;//已经在线
            } else if (model.userAuthorization(ml.getSrc(), ml.getPsw())) {
                check = 0;//验证通过
            } else {
                check = 1;
            }

            //接下来服务器返回登陆信息
            MsgLoginResp mlr = new MsgLoginResp(check);
            mlr.setTotalLen(14);
            mlr.send(ous);
            /*如果登陆完成发送好友列表*/
            if (check == 0) {
                UserJK = ml.getSrc();
                ThreadTool.RegThread(this);
                sendFriendList();
                isOnline = true;
                broadcastState(true);
            }
        }
        conn.close();
    }

    private void processChat() throws Exception {//聊天用的方法
        //TODO
        InputStream ins = client.getInputStream();
        DataInputStream dis = new DataInputStream(ins);
        int totalLen = dis.readInt();//读出包的长度
        byte[] data = new byte[totalLen - 4];//去掉用来装包的长度的四字节
        dis.readFully(data);
        //接下来解包信息，判断是什么信息然后进入不同的方法进行处理
        MsgHead msg = ParseTool.parseMsg(data);

        //接下来针对不同的信息进行处理
        if (msg.getType() == 0x04) {
            MsgChat msgChat = (MsgChat) msg;
            int from = msgChat.getSrc();
            int dest = msgChat.getDest();
            String msgText = msgChat.getMsgText();
            System.out.println(msgText);
            if ((!ChatTool.sendMsg(from, dest, msgText))) {
                System.out.println("保存至服务器，离线消息");
                ChatTool.saveOnServer(from, dest, msgText);
            }
        } else if (msg.getType() == 0x05) {//如果收到的是添加好友的消息(实现方式似乎有问题，还需要修改)
            System.out.println("Add friend request");
            MsgAddFriend maf = (MsgAddFriend) msg;
            int own_jk = maf.getSrc();
            int add_jk = maf.getAdd_ID();
            String list_name = maf.getList_name();
            DBConnector conn = DBConnector.getInstance();
            UserModel model = new UserModel(conn);
            int result = model.addFriend(add_jk, own_jk, list_name);
            System.out.println("Add finish " + result);
            MsgAddFriendResp mafr = new MsgAddFriendResp();
            mafr.setSrc(ServerJK.ServerJK);
            mafr.setDest(own_jk);
            mafr.setTotalLen(14);
            mafr.setType((byte) 0x55);
            if (result == 0) {//success
                model.addFriend(own_jk, add_jk, "新添加好友");
                //send add_jk new list
                mafr.setState((byte) 0);
                //send own_jk new list
            } else if (result == 1) {//不存在这个人
                mafr.setState((byte) 1);
            } else if (result == 2) {//如果已经存在了这个人
                mafr.setState((byte) 2);
            } else if (result == 3) {//创建列表失败
                mafr.setState((byte) 3);
            }
            mafr.send(ous);

            sendFriendList();

            //send Add_JK Friend list
            model.addFriend(own_jk, add_jk, list_name);
            //给被添加者更新列表
            server_thread st = ThreadMap.threadMap.get(String.valueOf(add_jk));
            if (st != null) {
                st.sendFriendList();
            }
            conn.close();
        } else if (msg.getType() == 0x44) {
            System.out.println("收到同意添加好友");
            MsgAddFriendResp mar = (MsgAddFriendResp) msg;
            DBConnector conn = DBConnector.getInstance();
            UserModel model = new UserModel(conn);
            int result = model.addFriend(mar.getSrc_id(), mar.getAgree_id(), mar.getSrc_add_listName());
            if (result == 1) {//如果能成功添加，添加另一个
                model.addFriend(mar.getAgree_id(), mar.getSrc_id(), mar.getAgree_listName());
                MsgAddConfirm macf = new MsgAddConfirm();
                macf.setTotalLen(45);
                macf.setType((byte) 0x15);
                macf.setSrc(ServerJK.ServerJK);
                macf.setDest(mar.getAgree_id());
                macf.setNewJKNum(mar.getAgree_id());
                macf.setNewPic(1);
                macf.setSrcJknum(mar.getSrc_id());
                macf.setNewListname(mar.getAgree_listName());

                String driver = "com.mysql.jdbc.Driver";
                String url = "jdbc:mysql://localhost:3306/imserver";
                String user = "root";
                String passwd = "521520";
                String srcname = "";
                String newName = "";
                try {
                    Class.forName(driver);
                } catch (ClassNotFoundException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                try {
                    Connection conn1 = DriverManager.getConnection(url, user, passwd);
                    if (!conn1.isClosed()) {
                        System.out.println("成功连接到数据库");
                    }
                    Statement stmt = conn1.createStatement();
                    ResultSet rs = stmt.executeQuery(String.format("select * from users where user_id=%d", macf.getSrcJknum()));
                    if (rs.next()) srcname = rs.getString("nickname");
                    rs = stmt.executeQuery(String.format("select * from users where user_id=%d", macf.getNewJKNum()));
                    if (rs.next()) newName = rs.getString("nickname");
                } catch (SQLException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
                macf.setNewNickname(newName);


                macf.send(ous);
                MsgAddConfirm macfsrc = new MsgAddConfirm();
                macfsrc.setTotalLen(45);
                macfsrc.setType((byte) 0x15);
                macfsrc.setSrc(ServerJK.ServerJK);
                macfsrc.setDest(mar.getSrc_id());
                macfsrc.setNewJKNum(mar.getAgree_id());
                macfsrc.setNewPic(1);
                macfsrc.setSrcJknum(mar.getAgree_id());
                macfsrc.setNewListname(mar.getSrc_add_listName());
                macfsrc.setNewNickname(srcname);
                server_thread st = ThreadMap.threadMap.get(String.valueOf(mar.getSrc_id()));
                macfsrc.send(st.ous);
            }


            conn.close();
        } else if (msg.getType() == 0x33)//如果是搜索
        {
            MsgSearch msearch = (MsgSearch) msg;
            DBConnector conn = DBConnector.getInstance();
            ResultSet rs = conn.query(String.format("select * from users where user_id=%d", msearch.getjknum()));
            if (rs.next()) {
                //如果有结果
                MsgSearchResult msr = new MsgSearchResult();
                msr.setType((byte) 0x34);
                msr.setTotalLen(32);
                msr.setDest(msearch.getSrc());
                msr.setSrc(ServerJK.LoginJK);
                msr.setJkNum(rs.getInt("user_id"));
                msr.setResult((byte) 0x01);
                msr.setName(rs.getString("nickname"));
                msr.setPic(rs.getInt("avatar"));
                msr.send(ous);
            } else {
                MsgSearchResult msr = new MsgSearchResult();
                msr.setType((byte) 0x34);
                msr.setTotalLen(32);
                msr.setDest(msearch.getSrc());
                msr.setSrc(ServerJK.LoginJK);
                msr.setJkNum(msearch.getjknum());
                msr.setPic(0);
                msr.setName("");
                msr.setResult((byte) 0x00);
                msr.send(ous);
            }
        } else if (msg.getType() == 0x24) {//添加好友的请求
            MsgAddFriend maf = (MsgAddFriend) msg;
            maf.setTotalLen(31);
            maf.setType((byte) 0x75);
            server_thread st = ThreadMap.threadMap.get(String.valueOf(maf.getDest()));
            if (st == null) {
                System.out.println("目标不在线,保存到服务器");
            }
            try {
                st.sendAddFriend(maf);
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

    }


    private void sendFriendList() throws SQLException, IOException {
        System.out.println("发送好友列表");
        DBConnector conn = DBConnector.getInstance();
        UserModel model = new UserModel(conn);
        UserInfo userInfo = model.getUserByJK(UserJK);
        MsgGroupList msgGroupList = new MsgGroupList(userInfo);
        msgGroupList.send(ous);
        conn.close();
    }

    private void refreshFriendList(int jknum, int dest, byte online) throws IOException {
        System.out.println("更新好友列表");
        MsgRefreshFriend msgRefreshFriend = new MsgRefreshFriend(jknum, dest, online);
        msgRefreshFriend.send(ous);
    }

    private void broadcastState(boolean online) throws SQLException, IOException {//当有客户端上线后向它的所有好友广播
        DBConnector conn = DBConnector.getInstance();
        UserModel model = new UserModel(conn);
        UserInfo user = model.getUserByJK(UserJK);
        for (int i = 0; i < user.getCollectionCount(); i++) {
            for (int j = 0; j < user.getBodyCount()[i]; j++) {
                server_thread st = ThreadMap.threadMap.get(String.valueOf(user.getBodyNum()[i][j]));
                if (st != null) {
                    //st.sendFriendList();//如果这个线程 不是空的（此人在线）则更新好友列表
                    if (online) {
                        st.refreshFriendList(UserJK, user.getBodyNum()[i][j], (byte) 0x01);
                    } else {
                        st.refreshFriendList(UserJK, user.getBodyNum()[i][j], (byte) 0x00);
                    }
                }
            }
        }
        conn.close();
    }

    public void sendMsg(int from, String msg) throws IOException {
        MsgChat msgChat = new MsgChat(from, UserJK, msg);
        msgChat.send(ous);
    }

    public void sendAddFriend(MsgAddFriend mar) throws IOException {
        MsgAddFriend msgAddFriend = new MsgAddFriend();
        msgAddFriend.setSrc_pic(mar.getSrc_pic());
        msgAddFriend.setSrc(mar.getDest());
        msgAddFriend.setDest(mar.getSrc());
        msgAddFriend.setList_name(mar.getList_name());
        msgAddFriend.setAdd_ID(mar.getAdd_ID());
        msgAddFriend.setTotalLen(mar.getTotalLen());

        msgAddFriend.setType((byte) 0x75);
        msgAddFriend.send(ous);
    }
}
