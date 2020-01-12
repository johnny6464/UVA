#include<iostream>
using namespace std;

int main()
{
	int bottles = 0;
	while (cin >> bottles)
	{
		int remain = 0;
		int sum = bottles;

		while (bottles >= 3)
		{
			sum += bottles / 3;
			bottles = bottles / 3 + bottles % 3;
		}
		if (bottles == 2)
		{
			sum += 1;
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}