#include<iostream>
#include<map>
#include<string>
using namespace std;

static map<char, double> notes{
	{'W', 1.0},
	{'H', 1.0 / 2},
	{'Q', 1.0 / 4},
	{'E', 1.0 / 8},
	{'S', 1.0 / 16},
	{'T', 1.0 / 32},
	{'X', 1.0 / 64}
};

int main()
{
	string composition;
	while (getline(cin, composition))
	{
		if (composition == "*")
		{
			break;
		}

		int correct = 0;
		double duration = 0;
		for (int i = 1; i < composition.size(); i++)
		{
			duration += notes[composition[i]];

			if (composition[i] == '/')
			{
				if (duration == 1)
				{
					correct++;
				}
				duration = 0.0;
			}
		}

		cout << correct << endl;
	}


	system("pause");
	return 0;
}