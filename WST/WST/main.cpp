#include<iostream>
#include<string>
using namespace std;

int chour, cmin, thour, tmin, ttime, ctime, totime;
string stime;

int main() {
	cout << ("Windows Shutdown Time v1.0") << endl;
	cout << "Welcome to Windows Shutdown Time. WST for short." << endl << "This program was made to make it easier to shutdown a PC at a specific time." << endl << "Please enter the current hour in a 24 hour standard" << endl;
	cin >> chour;
	cout << "Please enter the current minute." << endl;
	cin >> cmin;
	cout << "Please enter the Target hour" << endl;
	cin >> thour;
	cout << "Please enter the Target minute" << endl;
	cin >> tmin;
	cout << "You have entered that the current time is " << chour << ":" << cmin << " and the target shutdown time is " << thour << ":" << tmin << endl;
	if (chour > thour) {//if the target hour has a lower value than current hour it gets +24 so it counts properly
		thour = thour + 24;
	}
	chour = chour * 3600;
	thour = thour * 3600;
	tmin = tmin * 60;
	cmin = cmin * 60;
	ctime = chour + cmin;
	ttime = thour + tmin;
	totime = ttime - ctime;

	string stime = "shutdown -s /f -t " + to_string(totime);
	system(stime.c_str());
	system("pause");
	return 0;
}