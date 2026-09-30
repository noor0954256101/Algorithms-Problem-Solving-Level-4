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

sDate IncreaseDateByOneDays(sDate &Date)
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

sDate IncreaseDateByXDays(sDate &Date, short x)
{
	for (short i = 0; i < x; i++)
	{
		IncreaseDateByOneDays(Date);
	}
	return Date;
}

sDate IncreaseDateByOneWeek(sDate& Date)
{
	for (short i = 0; i < 7; i++)
	{
		IncreaseDateByOneDays(Date);
	}
	return Date;
}

sDate IncreaseDateByXWeeks(sDate& Date,short x)
{
	for (short i = 0; i < x; i++)
	{
		IncreaseDateByOneWeek(Date);
	}
	return Date;
}

sDate IncreaseDateByOneMonth(sDate& Date)
{
	if (lastMonthInYear(Date.Month))
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	short DayInMonth = HowDayInMonth(Date.Year, Date.Month);
	if (Date.Day > DayInMonth)
	{
		Date.Day = DayInMonth;
	}


	return Date;
}

sDate IncreaseDateByXMonths(sDate& Date, short x)
{
	for (short i = 0; i < x; i++)
	{
		IncreaseDateByOneMonth(Date);
	}
	return Date;
}

sDate IncreaseDateByOneYear(sDate& Date)
{
	Date.Year++;
	return Date;
}

sDate AddXYearInDate(sDate& Date, short x)
{
	for (short i = 0; i < x; i++)
	{
		IncreaseDateByOneYear(Date);
	}
	return Date;
}

sDate IncreaseDateByXYearsFaster(sDate& Date, short x)
{
	Date.Year+=x;
	return Date;
}

sDate IncreaseDateByOneDecade(sDate& Date)
{
	Date.Year += 10;
	return Date;
}

sDate IncreaseDateByXDecades(sDate& Date,short x)
{
	for (short i = 0; i < x; i++)
	{
		IncreaseDateByOneDecade(Date);
	}
	return Date;
}

sDate IncreaseDateByXDecadesFaster(sDate& Date, short x)
{
	Date.Year += x* 10;
	return Date;
}

sDate IncreaseDateByOneCentury(sDate& Date)
{
	Date.Year += 100;
	return Date;
}

sDate IncreaseDateByOneMillennium(sDate& Date)
{
	Date.Year += 1000;
	return Date;
}

void PrintDateAfterAdding(sDate Date)
{
	cout << "Date After :\n\n";

	Date = IncreaseDateByOneDays(Date);
	cout << " 01-Adding One Day is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDays(Date, 10);
	cout << " 02-Adding " << 10 << " Day is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneWeek(Date);
	cout << " 03-Adding One Week is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXWeeks(Date, 10);
	cout << " 04-Adding " << 10 << " Week is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneMonth(Date);
	cout << " 05-Adding One Month is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXMonths(Date, 5);
	cout << " 06-Adding " << 5 << " Month is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneYear(Date);
	cout << " 07-Adding One Year is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = AddXYearInDate(Date, 10);
	cout << " 08-Adding " << 10 << " Year is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXYearsFaster(Date, 10);
	cout << " 09-Adding " << 10 << " Year (Faster) is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneDecade(Date);
	cout << " 10-Adding One Decade is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDecades(Date, 10);
	cout << " 11-Adding " << 10 << " Decade is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByXDecadesFaster(Date, 10);
	cout << " 12-Adding " << 10 << " Decade (Faster) is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneCentury(Date);
	cout << " 13-Adding One Century is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

	Date = IncreaseDateByOneMillennium(Date);
	cout << " 14-Adding One Millennium is : "
		<< Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
}

int main()
{
	sDate Date = ReadFullDate();
	
	PrintDateAfterAdding(Date);

	system("pause>0");
	return 0;
}