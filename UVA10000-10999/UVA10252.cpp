#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	string a;
	string b;
	while (getline(cin, a) && getline(cin, b))
	{
		vector<char> record;
		for (int i = 0; i < a.size(); i++)
		{
			for (int j = 0; j < b.size(); j++)
			{
				if (a[i] == b[j] && a[i] != '*')
				{
					record.push_back(a[i]);
					a[i] = '*';
					b[j] = '*';
					break;
				}
			}
		}

		sort(record.begin(), record.end());
		for (int i = 0; i < record.size(); i++)
		{
			cout << record[i];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}