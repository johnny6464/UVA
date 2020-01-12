#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int main()
{
	int members = 0, calls = 0;
	int counter = 0;
	while (cin >> members >> calls)
	{
		if (members == 0 && calls == 0)
		{
			break;
		}

		map<string, vector<string>> record;
		map<string, int> nameId;
		string n1, n2;
		int id = 1;
		while (calls--)
		{
			cin >> n1 >> n2;
			if (nameId[n1] == 0)
			{
				nameId[n1] = id++;
				record[n1] = vector<string>();
			}
			if (nameId[n2] == 0)
			{
				nameId[n2] = id++;
			}

			record[n1].push_back(n2);
		}

		cout << "Calling circles for data set " << ++counter << ":" << endl;
	}

	system("pause");
	return 0;
}