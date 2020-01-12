#include<iostream>
using namespace std;

int main()
{
	int number;
	while (cin >> number)
	{
		if (number == 0)
		{
			break;
		}
		while (true)
		{
			int temp = 0;
			while (number > 0)
			{
				temp += number % 10;
				number /= 10;
			}

			number = temp;
			if (number < 10)
			{
				cout << temp << endl;
				break;
			}
		}
	}

	system("pause");
	return 0;
}