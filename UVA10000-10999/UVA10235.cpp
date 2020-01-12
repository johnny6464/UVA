#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		bool prime = 1;
		bool emirp = 1;

		int num1 = 0, num2 = 0;
		for (int i = 0; i < s.size(); i++)
		{
			num1 *= 10;
			num1 += s[i] - '0';
		}
		for (int i = s.size() - 1; i >= 0; i--)
		{
			num2 *= 10;
			num2 += s[i] - '0';
		}

		for (int i = 2; i < sqrt(num1) + 1; i++)
		{
			if (num1 % i == 0)
			{
				prime = 0;
				break;
			}
		}

		if (!prime)
		{
			cout << num1 << " is not prime." << endl;
			continue;
		}

		for (int i = 2; i < sqrt(num2) + 1; i++)
		{
			if (num2 % i == 0)
			{
				emirp = 0;
				break;
			}
		}

		if (!emirp || num1 == num2)
		{
			cout << num1 << " is prime." << endl;
		}
		else
		{
			cout << num1 << " is emirp." << endl;
		}
	}

	system("pause");
	return 0;
}