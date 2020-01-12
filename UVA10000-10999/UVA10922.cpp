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

		int degree = 1;
		int sum = 0;
		for (int i = 0; i < s.size(); i++)
		{
			sum += s[i] - '0';
		}

		if (sum % 9 != 0)
		{
			cout << s << " is not a multiple of 9." << endl;
			continue;
		}

		while (true)
		{
			int temp = 0;
			while (sum > 0)
			{
				temp += sum % 10;
				sum /= 10;
			}
			if (temp % 9 == 0)
			{
				degree++;
				sum = temp;

				if (temp == 9)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}

		cout << s << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
	}

	system("pause");
	return 0;
}