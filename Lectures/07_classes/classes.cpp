/*
	Classes and Objects
	===================

	Features (including but not limited to):
		- Complex types
		- Functions / Methods
		- Access to members can be restricted
		- Ctor and Dtor

*/

#include <iostream>

using namespace std;

class Date {

public:
	Date(unsigned int m = 1, unsigned int d = 1, unsigned int y = 1970) {
		month = m;
		day = d;
		year = y;
	}

	void print() {
		cout << month << " / " << day << " / " << year << endl;
		return;
	}

	void setMonth(int val) {
		if (val > 0 && val < 13) {
			month = val;
		}
		else {
			cout << "ERROR: Data = '" << val << "' out of range!" << endl;
		}
		return;
	}

private:
	unsigned int month;
	unsigned int day;
	unsigned int year;
};

int main() {

	Date d(1, 1, 2000);
	//compilation error
	//cout << d.month << endl;
	//d.month += 12;
	d.print();
	d.setMonth(5);
	d.print();
	d.setMonth(15);
	d.print();

	return 0;
}