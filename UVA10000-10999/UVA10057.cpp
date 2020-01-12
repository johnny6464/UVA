#include<iostream>
#include<vector>
#include<cmath>
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

		sort(v.begin(), v.end());

		int median1 = 0;
		int median2 = 0;
		int median_counter = 0;
		int all_possible = 0;
		if (v.size() & 1)
		{
			median1 = v[v.size() / 2];
			all_possible = 1;

			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == median1)
				{
					median_counter++;
				}
			}
		}
		else
		{
			median1 = v[v.size() / 2 - 1];
			median2 = v[v.size() / 2];
			all_possible = median2 - median1 + 1;

			for (int i = 0; i < v.size(); i++)
			{
				if (v[i] == median1 || v[i] == median2)
				{
					median_counter++;
				}
			}
		}

		cout << median1 << " " << median_counter << " " << all_possible << endl;
	}

	system("pause");
	return 0;
}