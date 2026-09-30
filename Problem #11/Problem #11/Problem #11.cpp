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

int NumOfDayInDate(short Day, short Year, short Month)
{
	int Days = 0;
	for (short i = 1; i < Month; i++)
	{
		Days += HowDayInMonth(Year, i);
	}
	Days += Day;
	return Days;
}

sDate GetDateInDays(short Days, short Year)
{
	sDate Date;

	Date.Year = Year;
	Date.Month = 1;


	short ReminingDays = Days;
	short MonthDay = 0;

	while (true)
	{
		MonthDay = HowDayInMonth(Year, Date.Month);

		if (ReminingDays > MonthDay)
		{
			ReminingDays -= MonthDay;
			Date.Month++;
		}
		else
		{
			Date.Day = ReminingDays;
			break;
		}
	}
	return Date;
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();
	short Days = NumOfDayInDate(Day, Year, Month);


	cout << "\nNumber of day Beging in the year is : " << Days << endl;

	sDate Date;

	Date = GetDateInDays(Days, Year);
	cout << "\nDate in [ " << Days << " ] is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;



	system("pause>0");
	return 0;
}