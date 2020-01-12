#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		vector<int> v;
		int S = 0;

		int nums = 0;
		cin >> nums;
		while (nums--)
		{
			int num = 0;
			cin >> num;
			v.push_back(num);
		}

		int counter = 0;
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = i + 1; j < v.size(); j++)
			{
				if (v[i] > v[j])
				{
					swap(v[i], v[j]);
					counter++;
				}
			}
		}
		
		cout << "Optimal train swapping takes " << counter << " swaps." << endl;
	}

	system("pause");
	return 0;
}