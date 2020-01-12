#include<iostream>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;

	int counter = 0;
	while (cases--)
	{
		int start[2] = { 0 };
		int end[2] = { 0 };
		cin >> start[0] >> start[1] >> end[0] >> end[1];

		int start_level = start[0] + start[1];
		int end_level = end[0] + end[1];

		int sum = 0;
		for (int i = start_level; i < end_level; i++)
		{
			sum += i + 1;
		}
		sum += end[0] - start[0];

		cout << "Case " << ++counter << ": " << sum << endl;
	}

	system("pause");
	return 0;
}