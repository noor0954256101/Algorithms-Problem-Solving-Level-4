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

short ReadHowDayAdd()
{
	short Day;
	cout << "\nPlease Enter How Need Add Days :";
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

sDate ReadFullDate()
{
	sDate Date;

	Date.Day = ReadDay();
	Date.Month = ReadMonth();
	Date.Year = ReadYear();
	return Date;
}

sDate ConvertDaysToDate(short AddDays,sDate Date)
{
	short ReminingDays = AddDays+NumOfDayInDate(Date.Day,Date.Year,Date.Month);
	short MonthDay = 0;

	Date.Month = 1;


	while (true)
	{
		MonthDay = HowDayInMonth(Date.Year, Date.Month);

		if (ReminingDays > MonthDay)
		{
			ReminingDays -= MonthDay;

			if (Date.Month >= 12)
			{
				Date.Year++;
				Date.Month = 0;
			}
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
	sDate Date;
	short Days = ReadHowDayAdd();

	Date = ReadFullDate();

	Date = ConvertDaysToDate(Days,Date);

	cout << "\nDate aftare Adding [ " << Days << " ] is : ";
	cout << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


	system("pause>0");
	return 0;
}