#include <iostream>
#include "Date.h"

Date::Date(int m, int d, int y) {
	month = m;
	day = d;
	year = y;
}

void Date::printDate() {
	std::cout << month << "/" << day << "/" << year << std::endl;
	return;
}

void Date::setMonth(int m) {
	month = m;
	return;
}