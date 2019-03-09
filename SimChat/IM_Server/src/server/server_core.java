package server;

import java.net.ServerSocket;
import java.net.Socket;


public class server_core {
	ServerSocket server;
	
	public void StartServer(int port) {
		try
		{
			server=new ServerSocket(port);
			System.out.println("服务器建立成功,开始监听.");
			while(true) {
				Socket client=server.accept();
				System.out.println("收到来自"+client.getRemoteSocketAddress()+"的连接请求");
				server_thread st=new server_thread(client);
				st.start();
			}
		}catch(Exception e) {
			e.printStackTrace();
		}
		
	}
	public void StopServer() {
		try {
			server.close();
			System.out.println("服务器已关闭。");
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	//测试服务器用
	public static void main(String[] args) {
		server_core server=new server_core();
		server.StartServer(10086);
	}
}
