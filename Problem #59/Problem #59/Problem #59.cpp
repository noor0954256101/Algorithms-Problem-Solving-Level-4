#include <iostream>
#include <string>
using namespace std;

struct sDate
{
	short Day;
	short Month;
	short Year;
};

struct stPeriods
{
	sDate DateStart;
	sDate DateEnd;
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

stPeriods ReadFullPeriods()
{
	stPeriods Periods;
	cout << "Enter Date Start\n";
	Periods.DateStart = ReadFullDate();
	cout << "Enter Date End\n";
	Periods.DateEnd = ReadFullDate();
	return Periods;
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

short HowDifferenceInDate1AndDate2(sDate Date1, sDate Date2, bool IncludingEndDay = false)
{
	short Difference = 0;
	while (CheckDateLess(Date1, Date2))
	{
		Difference++;
		Date1 = AddOneDayInDate(Date1);
	}
	return IncludingEndDay ? ++Difference : Difference;
}

short PeriodsLenth(stPeriods Periods, bool IncludingEndDay = false)
{
	return HowDifferenceInDate1AndDate2(Periods.DateStart, Periods.DateEnd, IncludingEndDay);
}

int main()
{
	stPeriods Periods = ReadFullPeriods();

	cout << "\Periods Lenth is : " << PeriodsLenth(Periods) << " Day(s).\n";
	cout << "Periods Lenth is (Including End Day) : " << PeriodsLenth(Periods,true) << " Day(s).\n\n";

	system("pause>0");
	return 0;
}