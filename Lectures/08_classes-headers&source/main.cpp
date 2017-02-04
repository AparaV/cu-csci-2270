#include <iostream>
#include "Date.h"

using namespace std;

int main() {

	Date today(2, 3, 2017);

	today.printDate();
	today.setMonth(5);
	today.printDate();

	return 0;
}