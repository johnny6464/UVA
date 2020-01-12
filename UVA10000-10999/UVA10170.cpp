#include<iostream>
using namespace std;

int main()
{
	long long init = 0;
	long long days = 0;
	while (cin >> init >> days)
	{
		long long now = 0;
		long long counter = init;
		while (true)
		{
			now += counter;

			if (now >= days)
			{
				cout << counter << endl;
				break;
			}
			counter++;
		}
	}

	system("pause");
	return 0;
}