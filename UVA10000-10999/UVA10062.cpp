#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Counter
{
	int ascii;
	int count;
};

bool compare(Counter c1, Counter c2);

int main()
{
	string s;
	bool first = 1;
	while (getline(cin, s))
	{
		if (!first)
		{
			cout << endl;
		}
		vector<Counter> v;
		for (int i = 0; i <= 128; i++)
		{
			Counter c;
			c.ascii = i;
			c.count = 0;
			v.push_back(c);
		}

		for (int i = 0; i < s.size(); i++)
		{
			v[int(s[i])].count++;
		}

		sort(v.begin(), v.end(), compare);

		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].count != 0)
			{
				cout << v[i].ascii << " " << v[i].count << endl;
			}
		}

		for (int i = 0; i < v.size(); i++)
		{
			v[i].count = 0;
		}
		
		first = 0;
	}

	system("pause");
	return 0;
}


bool compare(Counter c1, Counter c2)
{
	if (c1.count != c2.count)
	{
		return c1.count < c2.count;
	}
	else
	{
		return c1.ascii > c2.ascii;
	}
}