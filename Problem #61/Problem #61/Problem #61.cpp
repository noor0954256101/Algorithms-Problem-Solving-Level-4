#include <iostream>
#include <string>
using namespace std;

enum EnCompansDate
{
	Before = -1, Equal = 0, After = 1
};

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

sDate IncreaseDateByOneDays(sDate& Date)
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

bool IsDate1LeasDate2(sDate Date1, sDate Date2)
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

bool Date1EqualDate2(sDate Date1, sDate Date2)
{
	return(Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool CheckDate1AfterDate2(sDate Date1, sDate Date2)
{
	return((!IsDate1LeasDate2(Date1, Date2)) && (!Date1EqualDate2(Date1, Date2)));
}

EnCompansDate CompansDates(sDate Date1, sDate Date2)
{
	if (IsDate1LeasDate2(Date1, Date2))
		return EnCompansDate::Before;

	if (Date1EqualDate2(Date1, Date2))
		return EnCompansDate::Equal;

	return EnCompansDate::After;
}

bool CheckOverlap(stPeriods Periods1, stPeriods Periods2)
{
	if (
		CompansDates(Periods2.DateEnd, Periods1.DateStart) == EnCompansDate::Before
		||
		CompansDates(Periods2.DateStart, Periods1.DateEnd) == EnCompansDate::After
		)
		return false;

	return true;
}

short HowDifferenceInDate1AndDate2(sDate Date1, sDate Date2, bool IncludingEndDay = false)
{
	short Difference = 0;
	while (IsDate1LeasDate2(Date1, Date2))
	{
		Difference++;
		Date1 = IncreaseDateByOneDays(Date1);
	}
	return IncludingEndDay ? ++Difference : Difference;
}

short PeriodsLenth(stPeriods Periods, bool IncludingEndDay = false)
{
	return HowDifferenceInDate1AndDate2(Periods.DateStart, Periods.DateEnd, IncludingEndDay);
}

bool IsDateInPeriods(sDate Date, stPeriods Periods1)
{
	return !(
		CompansDates(Date, Periods1.DateStart) == EnCompansDate::Before
		||
		CompansDates(Date, Periods1.DateEnd) == EnCompansDate::After
		);
}

short HowCountDaysPeriods(stPeriods Periods1, stPeriods Periods2)
{
	short Periods1Lenth = PeriodsLenth(Periods1, true);
	short Periods2Lenth = PeriodsLenth(Periods2, true);
	short CountDays=0;

	if (CheckOverlap(Periods1, Periods2))
		return 0;

	if (Periods1Lenth < Periods2Lenth)
	{
		while (IsDate1LeasDate2(Periods1.DateStart, Periods1.DateEnd))
		{
			if (IsDateInPeriods(Periods1.DateStart, Periods2))
				CountDays++;
			Periods1.DateStart = IncreaseDateByOneDays(Periods1.DateStart);
		}
	}
	else
	{
		while (IsDate1LeasDate2(Periods2.DateStart, Periods2.DateEnd))
		{
			if (IsDateInPeriods(Periods2.DateStart, Periods1))
				CountDays++;
			Periods2.DateStart = IncreaseDateByOneDays(Periods2.DateStart);
		}
	}
	return CountDays;
}

int main()
{
	cout << "Piriods 1 :\n";
	stPeriods Periods1 = ReadFullPeriods();
	cout << "Piriods 2 :\n";
	stPeriods Periods2 = ReadFullPeriods();

	cout << "Count OvarLap Days is :" << HowCountDaysPeriods(Periods1, Periods2);

	system("pause>0");
	return 0;
}
