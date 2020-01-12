#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s;
	vector<string> v;

	while (getline(cin, s))
	{
		v.push_back(s);
	}

	bool first = true;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if (v[i][j] == '"')
			{
				if (first)
				{
					v[i].replace(j, 1, "``");
				}
				else
				{
					v[i].replace(j, 1, "''");
				}
				first = !first;
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	system("pause");
	return 0;
}