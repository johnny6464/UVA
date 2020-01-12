#include<iostream>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;

	int start = 0;
	int end = 0;
	int counter = 0;
	while (cases--)
	{
		cin >> start >> end;
		int sum = 0;
		for (int i = start; i <= end; i++)
		{
			if (i % 2 == 1)
			{
				sum += i;
			}
		}

		counter++;
		cout << "Case " << counter << ": " << sum << endl;
	}

	system("pause");
	return 0;
}