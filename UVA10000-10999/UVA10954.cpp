#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	int nums = 0;
	while (cin >> nums)
	{
		if (nums == 0)
		{
			break;
		}
		
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < nums; i++)
		{
			int num = 0;
			cin >> num;
			pq.push(num);
		}

		long long sum = 0;
		while (pq.size() != 1)
		{
			int cost = 0;
			cost += pq.top();
			pq.pop();
			cost += pq.top();
			pq.pop();
			sum += cost;
			pq.push(cost);
		}

		cout << sum << endl;
	}

	system("pause");
	return 0;
}