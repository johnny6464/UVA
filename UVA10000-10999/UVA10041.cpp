#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;
	while(cases--)
	{
		vector<int> v;
		int houses = 0;
		cin >> houses;
		while (houses--)
		{
			int loc = 0;
			cin >> loc;
			v.push_back(loc);
		}
		
		sort(v.begin(), v.end());

		int median = 0;
		if (v.size() % 2 != 0)
		{
			median = v[v.size() / 2];
		}
		else
		{
			median = (v[(v.size() / 2) - 1] + v[v.size() / 2]) / 2;
		}

		int sum = 0;
		for (int i = 0; i < v.size(); i++) 
		{
			sum += abs(median - v[i]);
		}

		cout << sum << endl;
	}

	system("pause");
	return 0;
}