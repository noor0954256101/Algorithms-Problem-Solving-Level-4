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

void SwapDate(sDate& Date1, sDate& Date2)
{
	sDate Tump;

	Tump.Day = Date1.Day;
	Tump.Month = Date1.Month;
	Tump.Year = Date1.Year;

	Date1.Day = Date2.Day;
	Date1.Month = Date2.Month;
	Date1.Year = Date2.Year;

	Date2.Day = Tump.Day;
	Date2.Month = Tump.Month;
	Date2.Year = Tump.Year;
}

short HowDifferenceInDate1AndDate2(sDate Date1, sDate Date2, bool IncludingEndDay = false)
{
	short Difference = 0;
	short SwapDateValue = 1;

	if (!CheckDateLess(Date1, Date2))
	{
		SwapDate(Date1, Date2);
		SwapDateValue = -1;
	}


	while (CheckDateLess(Date1, Date2))
	{
		Difference++;
		Date1 = AddOneDayInDate(Date1);
	}

	return IncludingEndDay ? ++Difference * SwapDateValue : Difference * SwapDateValue;
}

int main()
{
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	cout << "\nDifference is : " << HowDifferenceInDate1AndDate2(Date1, Date2) << " Day(s).\n";
	cout << "Difference is (Including End Day) : " << HowDifferenceInDate1AndDate2(Date1, Date2, true) << " Day(s).\n\n";

	system("pause>0");
	return 0;
}