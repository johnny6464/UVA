#include<iostream>
#include<string>
#include<map>
using namespace std;


int main()
{
	int cases = 0;
	cin >> cases;

	map<char, string> finger_table;
	finger_table['c'] = "0111001111";
	finger_table['d'] = "0111001110";
	finger_table['e'] = "0111001100";
	finger_table['f'] = "0111001000";
	finger_table['g'] = "0111000000";
	finger_table['a'] = "0110000000";
	finger_table['b'] = "0100000000";
	finger_table['C'] = "0010000000";
	finger_table['D'] = "1111001110";
	finger_table['E'] = "1111001100";
	finger_table['F'] = "1111001000";
	finger_table['G'] = "1111000000";
	finger_table['A'] = "1110000000";
	finger_table['B'] = "1100000000";

	cin.ignore();
	while (cases--)
	{
		string song;
		getline(cin, song);

		int counter[10] = { 0 };
		string current = "0000000000";
		for (int i = 0; i < song.size(); i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (current[j] == '0' && finger_table[song[i]][j] == '1')
				{
					counter[j]++;
				}
			}
			current = finger_table[song[i]];
		}

		for (int i = 0; i < 9; i++)
		{
			cout << counter[i] << " ";
		}
		cout << counter[9] << endl;
	}

	system("pause");
	return 0;
}