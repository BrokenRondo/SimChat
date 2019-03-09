package tools;
import dataBase.ThreadMap;
import server.server_thread;

public class ThreadTool {
    //注册线程到数据库
    public static void RegThread(server_thread thread){
        ThreadMap.threadMap.put(String.valueOf(thread.getUserJK()),thread);
    }

    public static void DelThread(int UserJK){
        ThreadMap.threadMap.remove(String.valueOf(UserJK));
    }
}
