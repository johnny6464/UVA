#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string order;
	int counter = 0;
	while (cin >> order)
	{
		if (order == "end")
		{
			break;
		}

		int len = order.size();
		vector<int> LIS(len, 1);

		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (int(order[i]) < int(order[j]))
				{
					LIS[j] = LIS[i] + 1 > LIS[j] ? LIS[i] + 1 : LIS[j];
				}
			}
		}

		int max = 0;
		for (int i = 0; i < len; i++)
		{
			if (max < LIS[i])
			{
				max = LIS[i];
			}
		}

		cout << "Case " << ++counter << ": " << max << endl;
	}

	system("pause");
	return 0;
}