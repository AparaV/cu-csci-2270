#ifndef DATE_H
#define DATE_H
//guards on the include contents. Only include if it hasn't already been included

//definition for Date class
class Date{
	private:
		int month;
		int day;
		int year;
	public:
		Date(int m, int d, int y);
		void printDate();
		void setMonth(int m);
};
#endif