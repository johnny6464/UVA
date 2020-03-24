#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		int count = 0;
		cin >> count;

		vector<int> v;
		string ins;
		int pos = 0;
		while (count--)
		{
			cin >> ins;

			if (ins == "LEFT")
			{
				pos--;
				v.push_back(-1);
			}
			else if (ins == "RIGHT")
			{
				pos++;
				v.push_back(1);
			}
			else
			{
				int temp;
				cin >> ins >> temp;

				if (v[temp - 1] == 1)
				{
					v.push_back(1);
					pos++;
				}
				else
				{
					v.push_back(-1);
					pos--;
				}
			}
		}

		cout << pos << endl;
	}

	system("pause");
	return 0;
}