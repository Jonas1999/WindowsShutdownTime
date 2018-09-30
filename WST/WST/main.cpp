#include<iostream>
#include <chrono>
#include<thread>
#include<WinUser.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;

char choc1;

int main() {
	cout << "Enter if you want to (S)hutdown or (L)ogoff" << endl;
	cin >> choc1;

	switch (choc1) {
	case 'S': cout << "shutdown switch";
		sleep_until(system_clock::time_point());
		break;
	case 'L': cout << "logoff switch";
		ExitWindowsEx(
			EWX_POWEROFF,
			EWX_FORCEIFHUNG
		);
		break;
	case 's': cout << "shutdown switch";
		break;
	case 'l': cout << "logoff switch";
		break;
	}
	system("pause");
}