#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int max = 1;
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				s[i] = s[i] - '0';
			}
			else if (s[i] >= 'A' && s[i] <= 'Z')
			{
				s[i] = s[i] - 'A' + 10;
			}
			else if (s[i] >= 'a' && s[i] <= 'z')
			{
				s[i] = s[i] - 'a' + 36;
			}
			else
			{
				continue;
			}

			sum += s[i];

			if (max < s[i])
			{
				max = s[i];
			}
		}

		bool possible = false;
		for (int i = max; i < 62; i++)
		{
			if (sum % i == 0)
			{
				cout << i + 1 << endl;
				possible = true;
				break;
			}
		}

		if (!possible)
		{
			cout << "such number is impossible!" << endl;
		}
	}

	system("pause");
	return 0;
}