#pragma warning(disable : 4996);

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;
};

sDate GetSystemDate()
{
	sDate Date;
	time_t t = time(0);
	tm* now = localtime(&t);
	Date.Year = now->tm_year + 1900;
	Date.Month = now->tm_mon + 1;
	Date.Day = now->tm_mday;
	return Date;
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

short YearToDay(short Year)
{
	return LeapYear(Year) ? 366 : 365;
}

short OrderDay(short Day, short Month, short Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;
	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

short OrderDay(sDate Date)
{
	int a = (14 - Date.Month) / 12;
	int y = Date.Year - a;
	int m = Date.Month + (12 * a) - 2;
	int d = (Date.Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string NameDayOrder(short OrderDay)
{
	string Arr[7] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };
	return Arr[OrderDay];
}

int NumOfDayInDate(sDate Date)
{
	int Days = 0;
	for (short i = 1; i < Date.Month; i++)
	{
		Days += HowDayInMonth(Date.Year, i);
	}
	Days += Date.Day;
	return Days;
}

bool IsEndOfWeek(short OrderDay)
{
	return  OrderDay == 6;
}

bool IsWeekEnd(short OrderDay)
{
	return OrderDay == 5||OrderDay==6;
}

bool IsBusinessDay(short OrderDay)
{
	return !IsWeekEnd(OrderDay);
}

short DaysUntilTheEndOfWeek(short OrderDay)
{
	return  6-OrderDay;
}

short DaysUntilTheEndOfMonth(sDate Date)
{
	return HowDayInMonth(Date.Year, Date.Month)-Date.Day;
}

short DaysUntilTheEndOfYear(sDate Date)
{
	return  YearToDay(Date.Year) - NumOfDayInDate(Date) ;
}

void PrintDateAfterAdding(sDate Date)
{
	short NumOrderDay = OrderDay(Date);
	cout << "Today is " << NameDayOrder(NumOrderDay) << "\t"
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl << endl;

	cout << "it is end of week ?\n";
	if (IsEndOfWeek(NumOrderDay))
		cout << "Yes, it is end of Week.\n\n";
	else
		cout << "No, it isn't end of Week.\n\n";

	cout << "It is of Weekend ? \n";
	if (IsWeekEnd(NumOrderDay))
		cout << "Yes, it is of Weekend.\n\n";
	else
		cout << "No, it isn't of Weekend.\n\n";

	cout << "It is of Business Day ? \n";
	if (IsBusinessDay(NumOrderDay))
		cout << "Yes, it is of Business Day.\n\n";
	else
		cout << "No, it isn't of Business Day.\n\n";


	cout << "\nDays Until The End Of Week : " << DaysUntilTheEndOfWeek(NumOrderDay)<< endl;

	cout << "\nDays Until The End Of Month : " << DaysUntilTheEndOfMonth(Date) << endl;

	cout << "\nDays Until The End Of Year : " << DaysUntilTheEndOfYear(Date) << endl;


}
int main()
{
	sDate Date ;

	Date.Day =25; Date.Month = 9; Date.Year = 2022;

	PrintDateAfterAdding(Date);

	system("pause>0");
	return 0;
}