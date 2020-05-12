#include "TcpClient.hpp"
#include <iostream>

TcpClient::TcpClient(std::string const & ip_address, unsigned int port_number, boost::asio::io_service & ios):
	m_ios(ios),
	m_remote_ip(boost::asio::ip::address::from_string(ip_address)),
	m_remote_port(port_number),
	m_remote_endpoint(m_remote_ip, m_remote_port),
	m_active_socket(m_ios)
{
	connectToServer();
}

void TcpClient::writeMessage(const std::vector<char> & message)
{
	boost::asio::async_write(m_active_socket, boost::asio::buffer(message),
		[this](const boost::system::error_code & error_code, size_t bytes)
	{
		handleWriteMessage(error_code);
	});
}

void TcpClient::connectToServer()
{
	m_active_socket.async_connect(m_remote_endpoint,
		[this](const boost::system::error_code & error_code)
	{
		handleConnect(error_code);
	});
}

void TcpClient::handleConnect(const boost::system::error_code & error_code)
{
	if (error_code)
	{
		std::cout << "unnable to connect : " << error_code.message()<< std::endl;
		closeConnection();
	}
	else
	{
		std::cout << "successfully connected" << std::endl;
	}
}

void TcpClient::handleWriteMessage(const boost::system::error_code & error_code)
{
	if (error_code)
	{
		std::cout << "problems with writing to the server : " << error_code.message() << std::endl;
		closeConnection();
	}
	else
	{
		std::cout << "message has been successfully written" << std::endl;
	}
}

void TcpClient::closeConnection()
{
	std::lock_guard<std::mutex> lock(m_socket_mutex);
	if (m_active_socket.is_open())
	{
		m_active_socket.close();
	}
}
