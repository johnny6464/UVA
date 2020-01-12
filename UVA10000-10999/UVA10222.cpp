#include<iostream>
#include<string>
using namespace std;

const char keyboard[] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

int main()
{
	string s;
	while (getline(cin, s))
	{
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == ' ' || s[i] == '\n')
			{
				cout << " ";
			}
			else
			{
				s[i] = tolower(s[i]);
				for (int j = 0; keyboard[j]; j++)
				{
					if (s[i] == keyboard[j])
					{
						cout << keyboard[j - 2];
						break;
					}
				}
			}
		}
		cout << endl;
	}
	

	system("pause");
	return 0;
}