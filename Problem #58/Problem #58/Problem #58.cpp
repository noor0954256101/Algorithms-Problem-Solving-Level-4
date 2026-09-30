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

int main()
{
	cout << "Piriods 1 :\n";
	stPeriods Periods1 = ReadFullPeriods();
	cout << "Piriods 2 :\n";
	stPeriods Periods2 = ReadFullPeriods();

	if (CheckOverlap(Periods1, Periods2))
		cout << "Yes,Is piriods overlab\n";
	else
		cout << "No,Is Not piriods overlab\n";

	system("pause>0");
	return 0;
}
