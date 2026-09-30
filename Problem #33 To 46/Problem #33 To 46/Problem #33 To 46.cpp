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

sDate DecreaseDateByOneDay(sDate& Date)
{
	if (LastDayInMonth(Date))
	{
		Date.Day--;
	}
	else if(Date.Day == 1 && Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
		Date.Day = HowDayInMonth(Date.Year, Date.Month);

	}
	else if (Date.Day == 1 )
	{ 
		Date.Month--;
		Date.Day = HowDayInMonth(Date.Year, Date.Month);
	}
	else
	{
		Date.Day--;
	}
	
	return Date;
}

sDate DecreaseDateByXDays(sDate& Date, short Days)
{
	for (short i = 0; i < Days; i++)
	{
		DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByOneWeek(sDate& Date)
{
	for (short i = 0; i < 7; i++)
	{
		DecreaseDateByOneDay(Date);
	}
	return Date;
}

sDate DecreaseDateByXWeeks(sDate& Date, short x)
{
	for (short i = 0; i < x; i++)
	{
		DecreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate DecreaseDateByOneMonth(sDate& Date)
{
	if ( Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	short DayInMonth = HowDayInMonth(Date.Year, Date.Month);
	if (Date.Day > DayInMonth)
	{
		Date.Day = DayInMonth;
	}


	return Date;
}

sDate DecreaseDateByXMonths(sDate& Date, short x)
{
	for (short i = 0; i < x; i++)
	{
		DecreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate DecreaseDateByOneYear(sDate& Date)
{
	Date.Year--;
	return Date;
}

sDate DecreaseDateByXYears(sDate& Date, short x)
{
	for (short i = 0; i < x; i++)
	{
		DecreaseDateByOneYear(Date);
	}
	return Date;
}

sDate DecreaseDateByXYearsFaster(sDate& Date, short x)
{
	Date.Year -= x;
	return Date;
}

sDate DecreaseDateByOneDecade(sDate& Date)
{
	Date.Year -= 10;
	return Date;
}

sDate DecreaseDateByXDecades(sDate& Date, short x)
{
	for (short i = 0; i < x; i++)
	{
		DecreaseDateByOneDecade(Date);
	}
	return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate& Date, short x)
{
	Date.Year -= x * 10;
	return Date;
}

sDate DecreaseDateByOneCentury(sDate& Date)
{
	Date.Year -= 100;
	return Date;
}

sDate DecreaseDateByOneMillennium(sDate& Date)
{
	Date.Year -= 1000;
	return Date;
}

void PrintDateAfterAdding(sDate Date)
{
	cout << "Date After :\n\n";

	Date = DecreaseDateByOneDay(Date);
	cout << " 01-Suptracting One Day is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDays(Date, 10);
	cout << " 02-Suptracting " << 10 << " Day is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneWeek(Date);
	cout << " 03-Suptracting One Week is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXWeeks(Date, 10);
	cout << " 04-Suptracting " << 10 << " Week is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneMonth(Date);
	cout << " 05-Suptracting One Month is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXMonths(Date, 5);
	cout << " 06-Suptracting " << 5 << " Month is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneYear(Date);
	cout << " 07-Suptracting One Year is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXYears(Date, 10);
	cout << " 08-Suptracting " << 10 << " Year is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXYearsFaster(Date, 10);
	cout << " 09-Suptracting " << 10 << " Year (Faster) is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneDecade(Date);
	cout << " 10-Suptracting One Decade is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDecades(Date, 10);
	cout << " 11-Suptracting " << 10 << " Decade is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByXDecadesFaster(Date, 10);
	cout << " 12-Suptracting " << 10 << " Decade (Faster) is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneCentury(Date);
	cout << " 13-Suptracting One Century is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = DecreaseDateByOneMillennium(Date);
	cout << " 14-Suptracting One Millennium is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main()
{
	sDate Date = ReadFullDate();

	PrintDateAfterAdding(Date);

	system("pause>0");
	return 0;
}