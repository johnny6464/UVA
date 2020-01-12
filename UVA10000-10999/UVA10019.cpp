#include<iostream>
using namespace std;

int toBinary(int);

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		int	M = 0;
		cin >> M;
		
		int b1 = toBinary(M);
		
		int b2 = 0;
		while (M > 0)
		{
			b2 += toBinary(M % 10);
			M /= 10;
		}
		cout << b1 << " " << b2 << endl;
	}

	system("pause");
	return 0;
}

int toBinary(int num)
{
	int counter = 0;
	while (num > 0)
	{
		if ((num & 1))
		{
			counter += 1;
		}
		num /= 2;
	}
	return counter;
}