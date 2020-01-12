#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int nums = 0;
	while (cin >> nums)
	{
		vector<int> v;
		while (nums--)
		{
			int num = 0;
			cin >> num;
			v.push_back(num);
		}

		vector<int> difference;
		for (int i = 0; i < v.size() - 1; i++)
		{
			difference.push_back(abs(v[i] - v[i + 1]));
		}

		sort(difference.begin(), difference.end());

		bool jolly = true;
		for (int i = 0; i < difference.size(); i++)
		{
			if (difference[i] != i + 1)
			{
				jolly = false;
				break;
			}
		}
		if (jolly)
		{
			cout << "Jolly" << endl;
		}
		else
		{
			cout << "Not jolly" << endl;
		}

	}

	system("pause");
	return 0;
}