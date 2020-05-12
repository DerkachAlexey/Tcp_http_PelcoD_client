#include <boost/asio.hpp>
#include <iostream>
#include "PelcoD.hpp"
#include "TcpClient.hpp"

using namespace boost;
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	asio::io_service ios;

	std::string ip_address = "94.234.165.123";
	unsigned int port_number = 10014;

	PelcoD pelco;
	std::vector<char> message;
	pelco.moveRightOnce(3, 3, message);
	
	
	TcpClient PelcoDClient(ip_address, port_number, ios);
	ios.run();
	
	return 0;
}