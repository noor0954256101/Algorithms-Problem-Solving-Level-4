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

string ReplaceWordInString(string S1, string StringToReplace,string sRepalceTo)
{
	short pos = S1.find(StringToReplace);
	while (pos != std::string::npos)
	{
		S1 = S1.replace(pos, StringToReplace.length(),
			sRepalceTo);
		pos = S1.find(StringToReplace);
	}
	return S1;
}

string FormatDate(sDate Date, string DateFortmat="dd/mm/yyyy")
{
	string ReplaceWordInFormate = "";
	ReplaceWordInFormate = ReplaceWordInString(DateFortmat, "dd", to_string(Date.Day));
	ReplaceWordInFormate = ReplaceWordInString(ReplaceWordInFormate, "mm", to_string(Date.Month));
	ReplaceWordInFormate = ReplaceWordInString(ReplaceWordInFormate, "yyyy", to_string(Date.Year));
	return ReplaceWordInFormate;

}

int main()
{
	string Datest = ReadDateStreing();

	sDate Date = convertStringToDate(Datest);

	cout << "\n" << FormatDate(Date);

	cout << "\n" << FormatDate(Date,"mm/dd/yyyy");

	cout << "\n" << FormatDate(Date,"yyyy-dd-mm");

	cout << "\n" << FormatDate(Date, "dd-mm-yyyy");

	cout << "\n" << FormatDate(Date, "Day : dd , Month : mm , Year : yyyy ");

	system("pause>0");
	return 0;
}