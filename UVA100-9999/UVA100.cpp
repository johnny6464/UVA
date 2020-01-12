#include<iostream>
using namespace std;

int main()
{
	int prev = 0, last = 0;
	while (cin >> prev >> last)
	{
		int max = 0;
		bool change = false;
		if (prev > last)
		{
			swap(prev, last);
			change = true;
		}

		for (int i = prev; i <= last; i++)
		{
			int num = i;
			int counter = 1;
			while (num != 1)
			{
				if (num % 2 == 0)
				{
					num /= 2;
				}
				else
				{
					num = num * 3 + 1;
				}
				counter++;
			}
			if (counter > max)
			{
				max = counter;
			}
		}
		if (change)
		{
			swap(prev, last);
		}

		cout << prev << " " << last << " " << max << endl;
	}

	system("pause");
	return 0;
}