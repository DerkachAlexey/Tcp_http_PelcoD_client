#include <vector>

class PelcoD
{
public:
	bool isControllable = false;
	void moveTopOnce(int panSpeed, int tiltSpeed, std::vector<char>& mess);
	void moveLeftOnce(int panSpeed, int tiltSpeed, std::vector<char>& mess);
	void moveBottomOnce(int panSpeed, int tiltSpeed, std::vector<char>& mess);
	void moveRightOnce(int panSpeed, int tiltSpeed, std::vector<char>& mess);
	void stopMoving(int panSpeed, int tiltSpeed, std::vector<char>& mess);
	void stopZooming(int zoomSpeed, std::vector<char>& mess);
	void moveHome(std::vector<char>& mess);
	void zoomInOnce(int zoomSpeed, std::vector<char>& mess);
	void zoomOutOnce(int zoomSpeed, std::vector<char>& mess);
};