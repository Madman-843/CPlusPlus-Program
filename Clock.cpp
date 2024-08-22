#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <string>
#include "Clock.h"
//Jacob Griggs 11/23/24
using namespace std;

int AddTime(int standard, int military, int sharedM, int sharedS, int selection) {
	if (selection == 1) {
		standard += 1;
		military += 1;
	}
	else if (selection == 2) {														/* This function is used when a user is adding time. */
		sharedM += 1;
	}
	else if (selection == 3) {
		sharedS += 1;
	}
	else {
		sharedS += 0;
	}
	return standard, military, sharedM, sharedS;
}

int Update(int standard, int military, int minutes, int seconds) {
	if (seconds > 59) {
		minutes += 1;
		seconds = 0;
	}
	if (minutes > 59) {
		standard += 1;
		military += 1;														/* This function updates the time. */
		minutes = 0;
	}
	if (standard > 12) {
		standard = 1;
	}
	if (military > 23) {
		military = 0;
	}
	return seconds, minutes, militaryHour, standardHour;
}

int Display(int standard, int military, int minutes, int seconds) {				/* This function displays the time. */
	string timeStamp;

	if (military >= 12 && military <= 23) {
		timeStamp = " PM";
	}
	if (military >= 0 && military < 12) {
		timeStamp = " AM";
	}

	cout << "\n\n\n\n\t*********************************\t*********************************" << endl;
	cout << "\t*\t  12-Hour Clock\t\t*\t*\t  24-Hour Clock\t\t*" << endl;
	cout << "\t*\t     " << militaryHour << ":" << minutes << ":" << seconds << "\t\t*" << endl;
	cout << "\t*********************************\t*********************************" << endl;

	return standard, military, minutes, seconds;
}

void Menu() {

	cout << "\n\n\t*********************************" << endl;
	cout << "\t*\t1 - Add One Hour\t*" << endl;
	cout << "\t*\t2 - Add One Minute\t*" << endl;                     //This function shows the Menu display
	cout << "\t*\t3 - Add One Second\t*" << endl;
	cout << "\t*\t4 - Exit the program\t*" << endl;
	cout << "\t*********************************" << endl;
}
