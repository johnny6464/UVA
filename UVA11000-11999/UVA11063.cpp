#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main()
{
	int nums = 0;
	int counter = 0;
	while (cin >> nums)
	{
		bool b2 = true;
		vector<int> v;
		while (nums--)
		{
			int num = 0;
			cin >> num;
			v.push_back(num);
		}

		if (v[0] < 1)
		{
			b2 = false;
		}

		for (int i = 0; i < v.size() - 1; i++)
		{
			if (v[i] >= v[i + 1])
			{
				b2 = false;
			}
		}

		set<int> s;
		for (int i = 0; i < v.size(); i++)
		{
			if (!b2)
			{
				break;
			}
			for (int j = i; j < v.size(); j++)
			{
				int temp = v[i] + v[j];
				if (s.count(temp))
				{
					b2 = false;
					break;
				}
				s.insert(temp);
			}
		}

		if (b2)
		{
			cout << "Case #" << ++counter << ": It is a B2-Sequence." << endl << endl;
		}
		else
		{
			cout << "Case #" << ++counter << ": It is not a B2-Sequence." << endl << endl;
		}
	}

	system("pause");
	return 0;
}