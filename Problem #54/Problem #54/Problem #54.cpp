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
	return OrderDay(Date.Day, Date.Month, Date.Year);
}

string NameDayOrder(short OrderDay)
{
	string Arr[7] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };
	return Arr[OrderDay];
}

bool IsWeekEnd(short OrderDay)
{
	return OrderDay == 5 || OrderDay == 6;
}

bool IsBusinessDay(short OrderDay)
{
	return !IsWeekEnd(OrderDay);
}

bool CheckDateLess(sDate Date1, sDate Date2)
{
	if (Date1.Year < Date2.Year)
	{
		return true;
	}
	else if (Date1.Year == Date2.Year)
	{
		if (Date1.Month < Date2.Month)
		{
			return true;
		}
		else if (Date1.Month == Date2.Month)
		{
			if (Date1.Day < Date2.Day)
			{
				return true;
			}
			return false;
		}
	}
	return false;
}

bool lastMonthInYear(short Month)
{
	return(Month == 12);
}

bool LastDayInMonth(sDate Date)
{
	return (HowDayInMonth(Date.Year, Date.Month) == Date.Day);
}

sDate AddOneDayInDate(sDate Date)
{
	if (LastDayInMonth(Date))
	{
		if (lastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}
	return Date;
}

short HowActycalVacationDay(sDate Date1, sDate Date2)
{
	short Difference = 0;
	while (CheckDateLess(Date1, Date2))
	{
		if (IsBusinessDay(OrderDay(Date1)))
		{
			Difference++;
		}
		Date1 = AddOneDayInDate(Date1);
	}
	return Difference;
}

int main()
{
	cout << "Vacation Starts.\n";
	sDate Date1 = ReadFullDate();
	cout << "Vacation Ends.\n";
	sDate Date2 = ReadFullDate();

	cout << "\nVacation From : " << NameDayOrder(OrderDay(Date1)) << " , "
		<< Date1.Day << "/" << Date1.Month << "/" << Date1.Year << endl;

	cout << "\nVacation To : " << NameDayOrder(OrderDay(Date2)) << " , "
		<< Date2.Day << "/" << Date2.Month << "/" << Date2.Year << endl;

	cout << "\n\nActycal Vacation Day is :" << HowActycalVacationDay(Date1, Date2);

	system("pause>0");
	return 0;
}