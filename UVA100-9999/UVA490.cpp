#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	string s;
	vector<string> v;
	int max = 0;
	while (getline(cin, s))
	{
		if (s.size() > max)
		{
			max = s.size();
		}
		v.push_back(s);
	}
	
	for (int i = 0; i < max; i++)
	{
		for (int j = v.size() - 1; j >= 0; j--)
		{
			if (i < v[j].size())
			{
				cout << v[j][i];
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}

	system("pause");
	return 0;
}