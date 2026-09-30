#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadDateStreing()
{
	string Date;
	cout << "Enter the Date DD/MM/YYYY : ";
	cin >> Date;
	return Date;
}

struct sDate
{
	short Day;
	short Month;
	short Year;
};

vector <string> SplitWord(string S1, string Delim)
{
	string sWord;
	short Pos = 0;
	vector <string> vsword;

	while ((Pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, Pos);
		if (sWord != "")
		{
			vsword.push_back(sWord);
		}

		S1.erase(0, Pos + Delim.length());

	}

	if (S1 != "")
	{
		vsword.push_back(S1);
	}
	return vsword;
}

sDate convertStringToDate(string stDate)
{
	sDate Date;
	vector<string>VDate = SplitWord(stDate, "/");
	Date.Day = stoi(VDate[0]);
	Date.Month = stoi(VDate[1]);
	Date.Year = stoi(VDate[2]);
	return Date;
}

string ConvertDateToString(sDate Date)
{
	return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

int main()
{
	string Datest = ReadDateStreing();

	sDate Date = convertStringToDate(Datest);
	cout << "\n\nDay :" << Date.Day << endl;
	cout << "Month :" << Date.Month << endl;
	cout << "Year :" << Date.Year << endl;

	cout << "\nyou Entered is : " <<ConvertDateToString(Date) ;
	system("pause>0");
	return 0;
}