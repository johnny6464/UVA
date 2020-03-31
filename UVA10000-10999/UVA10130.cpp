#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item
{
	int price;
	int weight;
};

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		int objects = 0;
		cin >> objects;

		vector<Item> list;
		for (int i = 0; i < objects; i++)
		{
			Item o;
			cin >> o.price >> o.weight;
			list.push_back(o);
		}

		int dp[31] = { 0 };
		for (int i = 0; i < objects; i++)
		{
			for (int j = 30; j >= list[i].weight; j--)
			{
				dp[j] = max(dp[j], dp[j - list[i].weight] + list[i].price);
			}
		}
		
		
		int men = 0;
		cin >> men;

		int total = 0;
		while (men--)
		{
			int weight = 0;
			cin >> weight;

			total += dp[weight];
		}

		cout << total << endl;
	}

	system("pause");
	return 0;
}