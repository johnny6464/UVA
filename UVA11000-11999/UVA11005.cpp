#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;

	int counter = 0;
	while (cases--)
	{
		vector<int> costs;
		for (int i = 0; i < 36; i++)
		{
			int cost = 0;
			cin >> cost;
			costs.push_back(cost);
		}

		cout << "Case " << ++counter << ":" << endl;
			
		int query = 0;
		cin >> query;
		while (query--)
		{
			int q = 0;
			cin >> q;

			vector<int> baseCost;
			int min = 999999999;
			for (int i = 2; i <= 36; i++)
			{
				int temp = q;
				vector<int> list;
				while (temp > 0)
				{
					list.push_back(temp % i);
					temp /= i;
				}

				int sum = 0;
				for (int i = 0; i < list.size(); i++)
				{
					sum += costs[list[i]];
				}
				if (min > sum)
				{
					min = sum;
				}
				baseCost.push_back(sum);
			}
			cout << "Cheapest base(s) for number " << q << ":";

			for (int i = 0; i <= 34; i++)
			{
				if(baseCost[i] == min)
				{
					cout << " " << i + 2;
				}
			}
			cout << endl;
		}
		if (cases != 0)
		{
			cout << endl;
		}
	}

	system("pause");
	return 0;
}