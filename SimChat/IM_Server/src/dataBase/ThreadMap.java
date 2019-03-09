package dataBase;


import server.server_thread;

import java.util.HashMap;
import java.util.Map;

/*用来保存服务器的线程，登陆后创建的线程放入Map中*/
public class ThreadMap {
    public static Map<String , server_thread>threadMap=new HashMap<String,server_thread>();
}
