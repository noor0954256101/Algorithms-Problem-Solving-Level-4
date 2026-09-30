#include <iostream>
#include <string>
using namespace std;

short ReadYear()
{
	short Year;
	cout << "Enter Year :";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Enter Month :";
	cin >> Month;
	return Month;
}

bool LeapYear(short Year)
{
	return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}

short YearToMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
	{
		return 0;
	}

	short NumOfDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (LeapYear(Year) ? 29 : 28) : NumOfDay[Month - 1];

}
int DayToHours(short Year, short Month)
{
	return YearToMonth(Year, Month) * 24;
}

int HoursToMin(short Year, short Month)
{
	return DayToHours(Year, Month) * 60;
}

int MinToSec(short Year, short Month)
{
	return HoursToMin(Year, Month) * 60;
}

void PrintTimeAll(short Year, short Month)
{
	cout << "\nNumber Of Day     in Month [ " << Month << " ] is : " << YearToMonth(Year, Month) << endl;
	cout << "Number Of Hours   in Month [ " << Month << " ] is : " << DayToHours(Year, Month) << endl;
	cout << "Number Of Min     in Month [ " << Month << " ] is : " << HoursToMin(Year, Month) << endl;
	cout << "Number Of Sec     in Month [ " << Month << " ] is : " << MinToSec(Year, Month) << endl;
	system("pause>0");
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();

	PrintTimeAll(Year, Month);

	return 0;
}