package tools;

import dataBase.ThreadMap;
import server.server_thread;

import java.io.IOException;


/*实现以下功能：
 * 将消息发送给用户，依据JK
 * 将未发送成功的信息存在服务器*/
public class ChatTool {
    public static boolean sendMsg(int from, int dest, String msg) {
        //向用户发送信息
        server_thread st = ThreadMap.threadMap.get(String.valueOf(dest));
        if (st == null) {
            System.out.println("目标不在线");
            return false;
        }
        try {
            st.sendMsg(from, msg);
            return true;
        } catch (IOException e) {
            e.printStackTrace();
        }
        return false;
    }
    /*如果用户不在线，则可以先保存在服务器中。目前设计的方式是为每个用户添加一个数据库，保存
    离线消息，在登陆的时候查看数据库，如果有离线消息则读取*/
    public static void saveOnServer(int from,int dest,String msg){
        
    }

}
