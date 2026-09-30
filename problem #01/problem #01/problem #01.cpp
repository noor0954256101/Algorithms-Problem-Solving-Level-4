#include<iostream>
#include<string>
using namespace std;

long ReadNumber()
{
	long Num;
	cout << "Enter the Number : ";
	cin >> Num;
	return Num;
}

string ReadNumberToText(long Num)
{
	if (Num == 0)
	{
		return " ";
	}

	if (Num >= 1 && Num <= 19)
	{
		string arr[] = { "",
		"One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		"Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
		return arr[Num] + " ";
	}
	if (Num >= 20 && Num <= 99)
	{
		string arr[] = {
		"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
		,"Ninety" };
		return arr[Num / 10] + " " + ReadNumberToText(Num % 10);
	}
	if (Num >= 100 && Num <= 190)
	{
		return "One Hundred" + ReadNumberToText(Num % 100);
	}
	if (Num >= 200 && Num <= 999)
	{
		return ReadNumberToText(Num / 100) + " Hundred " + ReadNumberToText(Num % 100);
	}
	if (Num >= 1000 && Num <= 1900)
	{
		return "One Thousand" + ReadNumberToText(Num % 1000);
	}
	if (Num >= 2000 && Num <= 999999)
	{
		return ReadNumberToText(Num / 1000) + " Thousand " + ReadNumberToText(Num % 1000);
	}
	if (Num >= 1000000 && Num <= 1999999)
	{
		return "One Million" + ReadNumberToText(Num % 1000000);
	}
	if (Num >= 2000000 && Num <= 9999999)
	{
		return ReadNumberToText(Num / 1000000) + " Million " + ReadNumberToText(Num % 1000000);
	}
	if (Num >= 1000000000 && Num <= 1999999999)
	{
	 return "One Billion" + ReadNumberToText(Num % 1000000000);
	}
	if (Num >= 2000000000 && Num <= 9999999999)
	{
		return ReadNumberToText(Num / 1000000000) + " Billion " + ReadNumberToText(Num % 1000000000);
	}

}


int main()
{
	long Num = ReadNumber();

	cout << ReadNumberToText(Num);
	system("pause>0");

	return 0;
}