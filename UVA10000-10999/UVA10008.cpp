#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;
	cin.ignore(1);

	vector<int> record(26, 0);
	while (cases--)
	{
		string s;
		getline(cin, s);

		for (int i = 0; i < s.size(); i++)
		{
			if (int(s[i]) >= 'a' && s[i] <= 'z')
			{
				record[int(s[i]) - 'a']++;
			}
			else if (int(s[i]) >= 'A' && s[i] <= 'Z')
			{
				record[int(s[i]) - 'A']++;
			}
		}
	}

	int max = 0;
	for (int i = 0; i < record.size(); i++)
	{
		if (record[i] > max)
		{
			max = record[i];
		}
	}

	for (int i = max; i > 0; i--)
	{
		for (int j = 0; j < 26; j++)
		{
			if (record[j] == i)
			{
				cout << char(j + 65) << " " << record[j] << endl;
			}
		}
	}


	system("pause");
	return 0;
}