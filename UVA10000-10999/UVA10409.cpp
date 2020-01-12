#include<iostream>
#include<string>
using namespace std;

int main()
{
	int rolls = 0;
	while (cin >> rolls)
	{
		if (rolls == 0)
		{
			break;
		}

		int now = 1;
		int N = 2, E = 4, S = 5, W = 3;
		for (int i = 0; i < rolls; i++)
		{
			string direction;
			cin >> direction;

			if (direction == "north")
			{
				N = now;
				now = S;
				S = 7 - N;
			}
			else if (direction == "south")
			{
				S = now;
				now = N;
				N = 7 - S;
			}
			else if (direction == "east")
			{
				E = now;
				now = W;
				W = 7 - E;
			}
			else if (direction == "west")
			{
				W = now;
				now = E;
				E = 7 - W;
			}
		}
		cout << now << endl;
	}

	system("pause");
	return 0;
}