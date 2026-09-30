#include <iostream>
#include <string>
using namespace std;

short ReadYear()
{
	short Year;
	cout << "Enter Year :";
	cin >> Year;
	return Year;
}
bool LeapYear(short Year)
{
	return (Year % 400 == 0 || Year % 4 == 0 && Year % 100 != 0);
}
int main()
{
	short Year = ReadYear();

	if (LeapYear(Year))
	{
		cout << "The Year is Leap Year :)\n";

	}
	else
	{
		cout << "The Year is Not Leap Year :(\n";

	}
	return 0;
}