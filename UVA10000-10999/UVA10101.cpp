#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

void convert(int, bool);

int main()
{
	long long num;
	int counter = 0;
	while (cin >> num)
	{
		counter++;
		cout << setw(4) << counter << ".";
		
		if (num < 100)
		{
			cout << " " << num;
		}
		else if (num / 1000000000 > 0)
		{
			int prev = (num / 1000000000) * 100;
			int last = num % 1000000000;
			convert(prev, false);
			convert(last, true);
		}
		else
		{
			convert(num, false);
		}
		cout << endl;
	}

	system("pause");
	return 0;
}


void convert(int num, bool addkuti)
{
	string bangla[4] = { "kuti", "lakh", "hajar", "shata" };
	if (num >= 10000000)
	{
		cout << " " << num / 10000000 << " " << bangla[0];
		num %= 10000000;
	}
	else
	{
		if (addkuti)
		{
			cout << " " << bangla[0];
		}
	}

	if (num >= 100000)
	{
		cout << " " << num / 100000 << " " << bangla[1];
		num %= 100000;
	}

	if (num >= 1000)
	{
		cout << " " << num / 1000 << " " << bangla[2];
		num %= 1000;
	}

	if (num >= 100)
	{
		cout << " " << num / 100 << " " << bangla[3];
		num %= 100;
	}

	if (num != 0)
	{
		cout << " " << num;
	}
}