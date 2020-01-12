#include<iostream>
using namespace std;

int gcd(int n1, int n2);

int main()
{
	int num = 0;
	int lookup[501] = { 0 };

	while (cin >> num)
	{
		if (num == 0)
		{
			break;
		}

		if (lookup[num] != 0)
		{
			cout << lookup[num] << endl;
			continue;
		}

		int sum = 0;
		for (int i = 1; i < num; i++)
		{
			for (int j = i + 1; j <= num; j++)
			{
				sum += gcd(j, i);
			}
		}
		lookup[num] = sum;
		cout << sum << endl;
	}

	system("pause");
	return 0;
}


int gcd(int n1, int n2)
{
	while (n1 % n2 != 0)
	{
		int temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}
	return n2;
}