#include<iostream>
#include<string>
using namespace std;

int mod(int n1, int n2);

int main()
{
	int cases = 0;
	cin >> cases;

	int counter = 0;
	while (cases--)
	{
		string s1, s2;
		cin >> s1 >> s2;

		int num1 = 0;
		int num2 = 0;
		for (int i = 0; i < s1.size(); i++)
		{
			num1 *= 2;
			num1 += s1[i] - '0';
		}

		for (int i = 0; i < s2.size(); i++)
		{
			num2 *= 2;
			num2 += s2[i] - '0';
		}

		int maxmod = mod(num1, num2);

		if (maxmod >= 2)
		{
			cout << "Pair #" << ++counter << ": All you need is love!" << endl;
		}
		else
		{
			cout << "Pair #" << ++counter << ": Love is not all you need!" << endl;
		}
	}

	system("pause");
	return 0;
}

int mod(int n1, int n2)
{
	if (n2 > n1)
	{
		int temp = n2;
		n2 = n1;
		n1 = temp;
	}

	while (n1 % n2 != 0)
	{
		int temp = n1 % n2;
		n1 = n2;
		n2 = temp;
	}
	return n2;
}