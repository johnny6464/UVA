#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int a = 0, b = 0;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
		{
			break;
		}

		int counter = 0;
		for (int i = a; i <= b; i++)
		{
			if (int(sqrt(double(i)) * int(sqrt(double(i))) == i))
			{
				counter++;
			}
		}

		cout << counter << endl;
	}

	system("pause");
	return 0;
}