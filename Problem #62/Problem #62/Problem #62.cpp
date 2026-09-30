#include <iostream>
#include <string>
using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;
};

short ReadYear()
{
	short Year;
	cout << "\nPlease Enter Year : ";
	cin >> Year;
	cout << endl << endl;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "\nPlease Enter Month :";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day;
	cout << "\nPlease Enter Day :";
	cin >> Day;
	return Day;
}

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
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

bool lastMonthInYear(short Month)
{
	return(Month == 12);
}

bool LastDayInMonth(sDate Date)
{
	return (HowDayInMonth(Date.Year, Date.Month) == Date.Day);
}

bool IsValidDate(sDate Date)
{
	if (Date.Day < 1 || Date.Day>31)
		return false;

	if (Date.Month < 1 || Date.Month>12)
		return false;

	if (Date.Month == 2)
	{
		if (LeapYear(Date.Year))
		{
			if (Date.Day > 29)
				return false;
		}
		else
		{
			if (Date.Day > 28)
				return false;
		}
	}

	short DaysInMonth = HowDayInMonth(Date.Year,Date.Month);

	if (Date.Day > DaysInMonth)
		return false;

	return true;
}
int main()
{
	sDate Date = ReadFullDate();

	if (IsValidDate(Date))
	{
		cout << "\nYes,Date is a Valied date\n";
	}
	else
	{
		cout << "\nNo,Date is Not a Valied date\n";

	}
	system("pause>0");
	return 0;
}
