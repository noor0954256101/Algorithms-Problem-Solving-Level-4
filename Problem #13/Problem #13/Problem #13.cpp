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
	else if(Date1.Year==Date2.Year)
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

int main()
{
	sDate Date1 = ReadFullDate();
	sDate Date2 = ReadFullDate();

	if(CheckDateLess(Date1,Date2))
	{
		cout << "Yes, Date1 is Less than Date 2 \n";
	}
	else
	{
		cout << "No, Date1 isn't Less than Date 2 \n";
	}

	system("pause>0");
	return 0;
}