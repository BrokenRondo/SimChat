package server;

import java.net.ServerSocket;
import java.net.Socket;


public class server_core {
	ServerSocket server;
	
	public void StartServer(int port) {
		try
		{
			server=new ServerSocket(port);
			System.out.println("�����������ɹ�,��ʼ����.");
			while(true) {
				Socket client=server.accept();
				System.out.println("�յ�����"+client.getRemoteSocketAddress()+"����������");
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
			System.out.println("�������ѹرա�");
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
	//���Է�������
	public static void main(String[] args) {
		server_core server=new server_core();
		server.StartServer(10086);
	}
}
