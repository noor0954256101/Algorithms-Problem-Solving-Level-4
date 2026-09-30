#include <iostream>
#include <string>
using namespace std;

enum enWeekDays {Sun = 0, Mon = 1, Tue = 2, Wednes = 3, Thurs = 4, Fri = 5, Satur = 6};

short ReadYear()
{
	short Year;
	cout << "Enter Year :";
	cin >> Year;
	return Year;
}

short ReadMonth()
{
	short Month;
	cout << "Enter Month :";
	cin >> Month;
	return Month;
}

short ReadDay()
{
	short Day;
	cout << "Enter Day :";
	cin >> Day;
	return Day;
}

short OrderDay(short Day, short Month, short Year)
{
	int a = (14 - Month) / 12;
	int y = Year - a;
	int m = Month + (12 * a) - 2;
	int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	return d;
}

string NameDayOrder(short OrderDay)
{
	string Arr[7] = { "Sun" , "Mon" , "Tue" , "Wednes" , "Thurs" , "Fri" , "Satur" };
	return Arr[OrderDay];
}

void PrintInfoDate(short Day, short Month, short Year)
{

	cout << "\nDate      :" << Day << "/" << Month << "/" << Year << endl;
	cout << "Day Order :" << OrderDay(Day, Month, Year)<< endl;
	cout << "Day Name  :" << NameDayOrder(OrderDay(Day, Month, Year))<< endl<< endl;
	system("pause>0");
}

int main()
{
	short Year = ReadYear();
	short Month = ReadMonth();
	short Day = ReadDay();

	PrintInfoDate(Day, Month, Year);

	return 0;
}