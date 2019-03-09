package dataBase;

import java.sql.*;





class ConnectorImpl extends DBConnector {
    ConnectorImpl() {
		String driver="com.mysql.jdbc.Driver";
		String url="jdbc:mysql://localhost:3306/imserver";
		String user="root";
		String passwd="521520";
		try {
			Class.forName(driver);
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			conn=DriverManager.getConnection(url, user, passwd);
			if(!conn.isClosed()) {
				System.out.println("成功连接到数据库");
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
    }
}
public abstract class DBConnector {
	 protected Connection conn;

	    public static DBConnector getInstance() {
	        return new ConnectorImpl();
	    }

	    public void close() throws SQLException {
	        conn.close();
	    }

	    public ResultSet query (String sql) throws SQLException {
	        Statement stmt = conn.createStatement();
	        ResultSet rs = stmt.executeQuery(sql);

	        return rs;
	    }

	    public int update(String sql) throws SQLException {
	        Statement stmt = conn.createStatement();
	        int res = stmt.executeUpdate(sql);
//	        conn.commit();
	        return res;
	    }
	    public int InstertandGetKey(String sql) throws SQLException {//插入到数据库并且返回主键
	    	PreparedStatement prpstmt=conn.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS);
	    	prpstmt.executeUpdate();
	    	ResultSet rs=prpstmt.getGeneratedKeys();
	    	if(rs.next()) {
	    		int id=rs.getInt(1);
	    		return id;
	    	}
	    	return -1;
	    }
}
