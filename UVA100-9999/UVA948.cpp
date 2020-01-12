#include<iostream>
using namespace std;

int main()
{
	int c[40] = { 0, 1 };
	for (int i = 2; i < 40; i++) 
	{
		c[i] = c[i - 1] + c[i - 2];
	}

	int nums = 0;
	cin >> nums;
	while (nums--) 
	{
		int num = 0;
		cin >> num;
		cout << num << " = ";

		bool consecutive = false;
		bool print = false;
		for (int i = 39; i >= 2; i--) 
		{
			if (num >= c[i] && !consecutive)
			{
				num -= c[i];
				consecutive = true;
				print = true;
				cout << "1";
			}
			else if (consecutive)
			{
				consecutive = false;
				cout << "0";
			}
			else if (print)
			{
				cout << "0";
			}
		}
		cout << " (fib)" << endl;
	}

	system("pause");
	return 0;
}