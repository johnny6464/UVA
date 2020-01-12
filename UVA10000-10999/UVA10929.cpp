#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		if (s == "0")
		{
			break;
		}

		int oddSum = 0;
		int evenSum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (i % 2 == 0)
			{
				evenSum += s[i] - '0';
			}
			else
			{
				oddSum += s[i] - '0';
			}
		}

		if ((evenSum - oddSum) % 11 == 0)
		{
			cout << s << " is a multiple of 11." << endl;
		}
		else
		{
			cout << s << " is not a multiple of 11." << endl;
		}
	}

	system("pause");
	return 0;
}