#include<iostream>
using namespace std;

int main()
{
	int h1 = 0, m1 = 0, h2 = 0, m2 = 0;
	while (cin >> h1 >> m1 >> h2 >> m2)
	{
		if (h1 == 0 && m1 == 0 && h2 == 0 && m2 == 0)
		{
			break;
		}

		int min = 0;
		if (h1 > h2 || (h1 == h2 && m1 >= m2))
		{
			h2 += 24;
		}

		min = (h2 - h1) * 60 + m2 - m1;

		cout << min << endl;
	}

	system("pause");
	return 0;
}