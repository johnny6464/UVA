#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;

	map<string, int> list;
	while (cases--)
	{
		string country, name;
		cin >> country;
		getline(cin, name);
		list[country]++;
	}

	for (map<string, int>::iterator i = list.begin(); i != list.end(); i++)
	{
		cout << i->first << " " << i->second << endl;
	}

	system("pause");
	return 0;
}