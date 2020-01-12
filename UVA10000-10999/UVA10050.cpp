#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		int days = 0;
		cin >> days;

		int hartals = 0;
		cin >> hartals;

		vector<int> v;
		for (int i = 0; i < hartals; i++)
		{
			int num = 0;
			cin >> num;
			v.push_back(num);
		}

		int lost = 0;
		for(int i = 1;i <= days;i++)
		{
			if (i % 7 == 6 || i % 7 == 0)
			{
				continue;
			}

			for (int j = 0; j < v.size(); j++)
			{
				if (i % v[j] == 0)
				{
					lost++;
					break;
				}
			}
		}
		cout << lost << endl;
	}

	system("pause");
	return 0;
}