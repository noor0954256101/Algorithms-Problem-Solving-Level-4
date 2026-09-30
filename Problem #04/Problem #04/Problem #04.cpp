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

bool LeapYear(short Year)
{
	return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}

short YearToDay(short Year)
{
	return LeapYear(Year) ? 366 : 365;
}

int DayToHours(short Year)
{
	return YearToDay(Year) * 24;
}

int HoursToMin(short Year)
{
	return DayToHours(Year) * 60;
}

int MinToSec(short Year)
{
	return HoursToMin(Year) * 60;
}

void PrintTimeAll(short Year)
{
	cout << "\nNumber Of Day     in Year [ " << Year << " ] is : " << YearToDay(Year)<< endl;
	cout << "Number Of Hours   in Year [ " << Year << " ] is : " << DayToHours(Year) << endl;
	cout << "Number Of Min     in Year [ " << Year << " ] is : " << HoursToMin(Year) << endl;
	cout << "Number Of Sec     in Year [ " << Year << " ] is : " << MinToSec(Year) << endl;
	system("pause>0");
}

int main()
{
	short Year = ReadYear();

	PrintTimeAll(Year);

	return 0;
}