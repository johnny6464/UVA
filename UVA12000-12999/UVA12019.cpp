#include<iostream>
#include<string>
using namespace std;

const int dayOfMonth[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
const string week[] = { "Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		int month = 0;
		int day = 0;
		cin >> month >> day;

		int firstday = 4;
		int totalday = 0;
		for (int i = 1; i < month; i++)
		{
			totalday += dayOfMonth[i];
		}
		totalday += day;

		cout << week[(firstday + totalday) % 7] << endl;
	}

	system("pause");
	return 0;
}