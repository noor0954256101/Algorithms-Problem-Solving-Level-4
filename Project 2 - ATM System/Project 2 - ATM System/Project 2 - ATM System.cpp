#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

void ATMMainMeuneScreen();
void Login();

string FilleClient = "ClientData.txt";

enum enATMMainMenueOptions { eQuickWithdraw = 1, eNormalWithdraw = 2, eDiposit = 3, eCheckBalance = 4, eLogout = 5 };

struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;


};

sClient CurentClient;

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
		vsword.push_back(S1);

	return vsword;
}

sClient ConvertLinetoRecord(string Line, string Seperator = "#//#")
{
	sClient Client;
	vector<string> vClientData;
	vClientData = SplitWord(Line, Seperator);
	Client.AccountNumber = vClientData[0];
	Client.PinCode = vClientData[1];
	Client.Name = vClientData[2];
	Client.Phone = vClientData[3];
	Client.AccountBalance = stod(vClientData[4]);
	return Client;
}

string ConvertRecordToLine(sClient Client, string Seperator = "#//#")
{
	string stClientRecord = "";

	stClientRecord += Client.AccountNumber + Seperator;
	stClientRecord += Client.PinCode + Seperator;
	stClientRecord += Client.Name + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += to_string(Client.AccountBalance);

	return stClientRecord;
}

vector <sClient> LoadCleintsDataFromFile(string FileName)
{
	vector <sClient> vClient;
	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string Line;
		sClient Client;
		while (getline(MyFile, Line))
		{
			Client = ConvertLinetoRecord(Line);
			vClient.push_back(Client);
		}
		MyFile.close();
	}
	return vClient;
}

vector<sClient> vClients = LoadCleintsDataFromFile(FilleClient);

vector <sClient> SaveCleintsDataToFile(string FileName, vector<sClient>& vClients)
{
	fstream MyFile;

	MyFile.open(FileName, ios::out);//overwrite
	string DataLine;

	if (MyFile.is_open())
	{
		for (sClient C : vClients)
		{
			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}
	return vClients;
}

bool FindUserByUserNameAndPassWord(string AccountNumber, string PinCode, sClient& Client)
{

	vector<sClient>vClient = LoadCleintsDataFromFile(FilleClient);

	for (sClient C : vClient)
	{
		if (C.AccountNumber == AccountNumber && C.PinCode == PinCode)
		{
			Client = C;
			return true;
		}
	}
	return false;
}

bool LoadUserInfo(string AccountNumber, string PinCode)
{
	if (FindUserByUserNameAndPassWord(AccountNumber, PinCode, CurentClient))
		return true;
	else
		return false;
}

short ReadATMMainMenueOption()
{
	cout << "Choose what do you want to do? [1 to 5]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

short ReadQuickWithdrawOption()
{
	cout << "\nChoose what do you want to do? [1 to 9]? ";
	short Choice = 0;
	cin >> Choice;

	return Choice;
}

void GoBackToATMMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause>0");
	ATMMainMeuneScreen();

}

void CheckBalance()
{
	cout << "Your Balance is : " << CurentClient.AccountBalance;
}

void CheckBalanceScreen()
{
	cout << "===========================================\n";
	cout << "\tCheck Balance Screen\n";
	cout << "===========================================\n";

	CheckBalance();
}

short ConvertOptionToNumber(short Option)
{
	switch (Option)
	{
	case 1:
	{
		return 20;
	}
	case 2:
	{
		return 50;
	}
	case 3:
	{
		return 100;
	}
	case 4:
	{
		return 200;
	}
	case 5:
	{
		return 400;
	}
	case 6:
	{
		return 600;
	}
	case 7:
	{
		return 800;
	}
	case 8:
	{
		return 1000;
	}
	case 9:
	{
		system("cls");
		GoBackToATMMainMenue();
		break;
	}
	}
}

void QuickWithdraw(short Option)
{
	short WithdrawAmount = ConvertOptionToNumber(Option);
	char Answer = 'n';

	while (WithdrawAmount > CurentClient.AccountBalance)
	{
		cout << "\n\nThe Balance is :" << CurentClient.AccountBalance << "\n\nPlease Enter amount Up to :" << CurentClient.AccountBalance << endl;
		GoBackToATMMainMenue();
	}
	cout << "\n\nAre you sure you want Withdraw this client? y/n ? ";
	cin >> Answer;


	if (Answer == 'y' || Answer == 'Y')
	{
		CurentClient.AccountBalance -= WithdrawAmount;

		cout << "\n\nClient WithDraw Successfully.\n\nBalance Now is : " << CurentClient.AccountBalance << endl;

		for (sClient& C : vClients)
		{
			C = CurentClient;
			break;
		}

		SaveCleintsDataToFile(FilleClient, vClients);

		vClients = LoadCleintsDataFromFile(FilleClient);
	}
}

void QuickWithdrawScreen()
{
	cout << "===========================================\n";
	cout << "\tQuick Withdraw Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] 20. " << "\t[2] 50\n";
	cout << "\t[3] 100." << "\t[4] 200\n";
	cout << "\t[5] 400." << "\t[6] 600\n";
	cout << "\t[7] 800." << "\t[8] 1000\n";
	cout << "\t[9] Exit.\n";
	cout << "===========================================\n";
	CheckBalance();
	QuickWithdraw(ReadQuickWithdrawOption());
}

int ReadNormalWithdrawAmount()
{
	int WithdrawAmount = 0;
	cout << "\n\nPlease Enter Withdraw Amount? ";
	cin >> WithdrawAmount;

	while (WithdrawAmount % 5 != 0)
	{
		cout << "\n\nPlease Enter Withdraw Amount multiple of 5? ";
		cin >> WithdrawAmount;
	}

	return WithdrawAmount;
}

void NormalWithdraw()
{
	int WithdrawAmount = ReadNormalWithdrawAmount();
	char Answer = 'n';

	if (WithdrawAmount > CurentClient.AccountBalance)
	{
		cout << "\n\nThe Balance is :" << CurentClient.AccountBalance << "\n\nPlease Enter amount Up to :" << CurentClient.AccountBalance << endl;
		GoBackToATMMainMenue();
	}

	cout << "\n\nAre you sure you want Withdraw y/n ? ";
	cin >> Answer;


	if (Answer == 'y' || Answer == 'Y')
	{
		CurentClient.AccountBalance -= WithdrawAmount;

		cout << "\n\nClient WithDraw Successfully.\n\nBalance Now is : " << CurentClient.AccountBalance << endl;

		for (sClient& C : vClients)
		{
			C = CurentClient;
			break;
		}

		SaveCleintsDataToFile(FilleClient, vClients);

		vClients = LoadCleintsDataFromFile(FilleClient);

	}
}

void NormalWithdrawScreen()
{
	cout << "===========================================\n";
	cout << "\tNormal Withdraw Screen\n";
	cout << "===========================================\n";

	NormalWithdraw();
}

void Depositinfo()
{
	short depositAmount;
	char Answer = 'n';


		cout << "Enter deposit amount : ";
		cin >> depositAmount;

		cout << "\n\nAre you sure you want Deposit this client? y/n ? ";
		cin >> Answer;


		if (Answer == 'y' || Answer == 'Y')
		{
			CurentClient.AccountBalance += depositAmount;

			for (sClient& C : vClients)
			{
				C = CurentClient;
				break;
			}

			SaveCleintsDataToFile(FilleClient, vClients);

			vClients = LoadCleintsDataFromFile(FilleClient);

			cout << "\n\nClient Deposit Successfully.\n\nBalance Now is : " << CurentClient.AccountBalance << endl;
		}
}

void DepositClientScreen()
{
	cout << "- - - - - - - - - - - - - - - - - - - - -\n";
	cout << "\t   Deposit Screen\n";
	cout << "- - - - - - - - - - - - - - - - - - - - -\n";

	Depositinfo();
}

void PerfromMainMenueOption(enATMMainMenueOptions ATMMenueOptions)
{
	switch (ATMMenueOptions)
	{
	case enATMMainMenueOptions::eQuickWithdraw:
	{
		system("cls");
		QuickWithdrawScreen();
		GoBackToATMMainMenue();
		break;
	}
	case enATMMainMenueOptions::eNormalWithdraw:
		system("cls");
		NormalWithdrawScreen();
		GoBackToATMMainMenue();
		break;

	case enATMMainMenueOptions::eDiposit:
		system("cls");
		DepositClientScreen();
		GoBackToATMMainMenue();
		break;

	case enATMMainMenueOptions::eCheckBalance:
		system("cls");
		CheckBalanceScreen();
		GoBackToATMMainMenue();
		break;

	case enATMMainMenueOptions::eLogout:
		system("cls");
		Login();
		break;
	}

}

void ATMMainMeuneScreen()
{
	vClients = LoadCleintsDataFromFile(FilleClient);

	system("cls");
	cout << "===========================================\n";
	cout << "\tATM Main Menue Screen\n";
	cout << "===========================================\n";
	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Diposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "===========================================\n";
	PerfromMainMenueOption((enATMMainMenueOptions)ReadATMMainMenueOption());
}

void Login()
{
	bool LoginFaild = false;
	string AccountNumber, PinCode;
	do
	{
		system("cls");
		cout << "- - - - - - - - - - - - - - - - - - - - -\n";
		cout << "\t   Login Screen\n";
		cout << "- - - - - - - - - - - - - - - - - - - - -\n";

		if (LoginFaild)
		{
			cout << "Invalid Account Number/Pin Code ! \n";
		}

		cout << "\nEnter Account Number : ";
		cin >> AccountNumber;

		cout << "\nEnter Pin Code : ";
		cin >> PinCode;

		LoginFaild = !LoadUserInfo(AccountNumber, PinCode);
	} while (LoginFaild);

	ATMMainMeuneScreen();
}

int main()
{
	Login();
	return 0;
}