#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		if (n < 2 || m < 2 || n < m)
		{
			cout << "Boring!" << endl;
			continue;
		}
		
		int power = 0;
		bool boring = 1;
		for (int i = 0; i < 100; i++)
		{
			if (n == pow(m, i))
			{
				power = i;
				boring = 0;
				break;
			}

			if (n < pow(m, i))
			{
				cout << "Boring!" << endl;
				break;
			}
		}

		if (!boring)
		{
			for (int i = power; i > 0; i--)
			{
				cout << int(pow(m, i)) << " ";
			}
			cout << 1 << endl;
		}
	}

	system("pause");
	return 0;
}