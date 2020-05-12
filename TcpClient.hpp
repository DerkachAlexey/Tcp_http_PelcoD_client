#include <string>
#include <boost/asio.hpp>
#include <mutex>

using tcp = boost::asio::ip::tcp;

class TcpClient
{
private:
	boost::asio::io_service & m_ios;
	tcp::socket m_active_socket;
	boost::asio::ip::address m_remote_ip;
	tcp::endpoint m_remote_endpoint;
	unsigned int m_remote_port;
	std::mutex m_socket_mutex;
public:
	TcpClient(std::string const & ip_address, unsigned int port_number, boost::asio::io_service & ios);
	void writeMessage(const std::vector<char> & message);
private:
	void connectToServer();
	void handleConnect(const boost::system::error_code & error_code);
	void handleWriteMessage(const boost::system::error_code & error_code);
	void closeConnection();
};