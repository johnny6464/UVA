#include<iostream>
#include<string>
#include<map>
#include<iomanip>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;
	getchar();
	getchar();

	while (cases--)
	{
		string s;
		map<string, int> species;
		double counter = 0;
		while (getline(cin, s))
		{
			if (s == "")
			{
				break;
			}
			species[s]++;
			counter++;
		}

		for (map<string, int>::iterator i = species.begin(); i != species.end(); i++)
		{
			cout << fixed << setprecision(4) << i->first << " " << i->second / counter * 100 << endl;
		}

		if (cases != 0)
		{
			cout << endl;
		}
	}

	system("pause");
	return 0;
}