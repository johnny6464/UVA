#include<iostream>
using namespace std;

int main()
{
	int prev = 0, last = 0;
	while (cin >> prev >> last) 
	{
		if (prev == 0 && last == 0)
		{
			break;
		}

		int carry = 0;
		bool carried = false;
		while (prev > 0 || last > 0)
		{
			int a = prev % 10;
			int b = last % 10;
			if (a + b > 9 || (a + b == 9 && carried))
			{
				carry++;
				carried = true;
			}
			else
			{
				carried = false;
			}

			prev /= 10;
			last /= 10;
		}

		if (carry == 0)
		{
			cout << "No carry operation." << endl;
		}
		else if (carry == 1)
		{
			cout << "1 carry operation." << endl;
		}
		else
		{
			cout << carry << " carry operations." << endl;
		}
	}

	system("pause");
	return 0;
}