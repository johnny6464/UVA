#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

struct Unit
{
	int num = 0;
	int remainder = 0;
};

bool compare(Unit a, Unit b);

int main()
{
	int nums = 0;
	int mod = 0;
	while (cin >> nums >> mod)
	{
		cout << nums << " " << mod << endl;
		if (nums == 0 && mod == 0)
		{
			break;
		}

		vector<Unit> v;
		while (nums--)
		{
			Unit u;
			cin >> u.num;
			u.remainder = u.num % mod;
			v.push_back(u);
		}
		
		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].num << endl;
		}
	}

	system("pause");
	return 0;
}


bool compare(Unit a, Unit b)
{
	if (a.remainder < b.remainder)
	{
		return true;
	}
	else if (a.remainder > b.remainder)
	{
		return false;
	}
	else
	{
		if ((a.num & 1) && !(b.num & 1))
		{
			return true;
		}
		else if (!(a.num & 1) && (b.num & 1))
		{
			return false;
		}
		else
		{
			if (!(a.num & 1) && !(b.num & 1))
			{
				if (a.num < b.num)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (a.num > b.num)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
}