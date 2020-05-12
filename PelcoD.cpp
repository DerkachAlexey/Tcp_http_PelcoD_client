#include "PelcoD.hpp"

void PelcoD::moveTopOnce(int panSpeed, int tiltSpeed, std::vector<char> &mess)
{
	mess = std::vector<char>(9);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x06;
	mess[3] = 0x01;
	mess[4] = panSpeed % 255;
	mess[5] = tiltSpeed % 255;
	mess[6] = 0x03;
	mess[7] = 0x01;
	mess[8] = 0xff;
}

void PelcoD::moveLeftOnce(int panSpeed, int tiltSpeed, std::vector<char> &mess)
{
	mess = std::vector<char>(9);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x06;
	mess[3] = 0x01;
	mess[4] = panSpeed % 255;
	mess[5] = tiltSpeed % 255;
	mess[6] = 0x01;
	mess[7] = 0x03;
	mess[8] = 0xff;
}

void PelcoD::moveBottomOnce(int panSpeed, int tiltSpeed, std::vector<char> &mess)
{
	mess = std::vector<char>(9);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x06;
	mess[3] = 0x01;
	mess[4] = panSpeed % 255;
	mess[5] = tiltSpeed % 255;
	mess[6] = 0x03;
	mess[7] = 0x02;
	mess[8] = 0xff;
}

void PelcoD::moveRightOnce(int panSpeed, int tiltSpeed, std::vector<char>& mess)
{
	mess = std::vector<char>(9);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x06;
	mess[3] = 0x01;
	mess[4] = panSpeed % 255;
	mess[5] = tiltSpeed % 255;
	mess[6] = 0x02;
	mess[7] = 0x03;
	mess[8] = 0xff;
}

void PelcoD::stopMoving(int panSpeed, int tiltSpeed, std::vector<char>& mess)
{
	mess = std::vector<char>(9);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x06;
	mess[3] = 0x01;
	mess[4] = panSpeed % 255;
	mess[5] = tiltSpeed % 255;
	mess[6] = 0x03;
	mess[7] = 0x03;
	mess[8] = 0xff;
}

void PelcoD::stopZooming(int zoomSpeed, std::vector<char> &mess)
{
	mess = std::vector<char>(6);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x04;
	mess[3] = 0x07;
	mess[4] = 0x00;
	mess[5] = 0xff;
}

void PelcoD::moveHome(std::vector<char> &mess)
{
	mess = std::vector<char>(5);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x06;
	mess[3] = 0x04;
	mess[4] = 0xff;
}

void PelcoD::zoomInOnce(int zoomSpeed, std::vector<char> &mess)
{
	mess = std::vector<char>(6);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x04;
	mess[3] = 0x07;
	mess[4] = 0x20 + zoomSpeed;
	mess[5] = 0xff;
}

void PelcoD::zoomOutOnce(int zoomSpeed, std::vector<char> & mess)
{
	mess = std::vector<char>(6);
	mess[0] = 0x81;
	mess[1] = 0x01;
	mess[2] = 0x04;
	mess[3] = 0x07;
	mess[4] = 0x30 + zoomSpeed;
	mess[5] = 0xff;
}
