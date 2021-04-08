#include<iostream>
#include <ctime> 
#include <string>
// https://www.cplusplus.com/forum/beginner/222367/
int targetHour, targetMin, targetTime, currentTime, totalTime;

int main() {
	system("shutdown -a");
	std::cout << "Windows Shutdown Time v2.0\n";
	std::cout << "Welcome to Windows Shutdown Time. WST for short.\nThis program was made to make it easier to shutdown a PC at a specific time.\n";
	std::cout << "Please enter the Target hour\n";
	std::cin >> targetHour;
	std::cout << "Please enter the Target minute\n";
	std::cin >> targetMin;
	const std::time_t now = std::time(nullptr);
	const std::tm calendar_time = *std::localtime(std::addressof(now));
	std::cout << "The current time is " << calendar_time.tm_hour << ":" << calendar_time.tm_min << " and the target shutdown time is " << targetHour << ":" << targetMin << '\n';
	if (calendar_time.tm_hour > targetHour) {//if the target hour has a lower value than current hour it gets +24 so it counts properly
		targetHour = targetHour + 24;
	}
	targetHour = targetHour * 3600;
	targetMin = targetMin * 60;
	currentTime = (calendar_time.tm_hour * 3600) + (calendar_time.tm_min * 60);
	targetTime = targetHour + targetMin;
	totalTime = targetTime - currentTime;

	std::string stime = "shutdown -s /f -t " + std::to_string(totalTime);
	system(stime.c_str());
	system("pause");
	return 0;
}