#include<iostream>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;

	int a = 0;
	int b = 0;
	while (cases--)
	{
		cin >> a >> b;
		if (a % 2 == 0 && b % 2 != 0
			|| a % 2 != 0 && b % 2 == 0
			|| a < b)
		{
			cout << "impossible" << endl;
			continue;
		}

		bool match = false;
		for (int i = a; i >= a / 2; i--)
		{
			if (i - (a - i) == b)
			{
				cout << i << " " << a - i << endl;
				match = true;
				break;
			}
		}

		if (!match)
		{
			cout << "impossible" << endl;
		}
	}

	system("pause");
	return 0;
}