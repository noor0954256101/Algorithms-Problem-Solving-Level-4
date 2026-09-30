#include <iostream>
#include <string>
#include <iomanip>
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

short HowDayInMonth(short Year, short Month)
{
	if (Month < 1 || Month>12)
	{
		return 0;
	}

	short NumOfDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

	return (Month == 2) ? (LeapYear(Year) ? 29 : 28) : NumOfDay[Month - 1];

}

short OrderDay(short Day, short Month, short Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;
	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string NameMonthOrder(short Month)
{
	string Arr[12] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };
	return Arr[Month - 1];
}

void PrintCalendarMonth(short Day, short Month, short Year)
{
	short NumOfMonth = HowDayInMonth(Year, Month);
	short orderDay = OrderDay(1, Month, Year);

	cout << "\n   ________________" << NameMonthOrder(Month) << "_______________\n\n";

	cout << "   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
	int i;

	for (i = 0; i < orderDay; i++)
	{
		cout << "     ";
	}

	for (short j = 1; j <= NumOfMonth; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			cout << endl;
		}
	}
	cout << "\n   __________________________________\n";
}

void PrintCalendarYear(short Year)
{
	cout << "\n  _______________________________________\n\n";
	cout << "\t   Calendar - " << Year ;
	cout << "\n  _______________________________________\n";

	for (short i = 1; i <= 12; i++)
	{
		PrintCalendarMonth(1, i, Year);
		cout << endl << endl;
	}
}

int main()
{
	short Year = ReadYear();

	PrintCalendarYear(Year);
	system("pause>0");
	return 0;
}