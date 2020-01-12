#include<iostream>
#include<string>
using namespace std;

int main()
{
	int num = 0;
	while (cin >> num)
	{
		if (num == 0)
		{
			break;
		}

		string binary;
		int counter = 0;
		while (num > 0)
		{
			if (num & 1)
			{
				binary = "1" + binary;
				counter += 1;
			}
			else
			{
				binary = "0" + binary;
			}
			num /= 2;
		}

		cout << "The parity of " << binary << " is " << counter << " (mod 2)." << endl;
	}

	system("pause");
	return 0;
}