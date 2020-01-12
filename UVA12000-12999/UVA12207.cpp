#include<iostream>
#include<deque>
using namespace std;

int main()
{
	int P = 0, C = 0;
	int counter = 0;
	while (cin >> P >> C)
	{
		if (P == 0 && C == 0)
		{
			break;
		}
		cout << "Case " << ++counter << ":" << endl;

		deque<int> d;
		deque<int>::iterator iter;
		for (int i = 1; i <= 1000 && i <= P; i++)
		{
			d.push_back(i);
		}

		while (C--)
		{
			char cmd;
			int num = 0;
			cin >> cmd;

			if (cmd == 'N')
			{
				cout << d.front() << endl;
				d.push_back(d.front());
				d.pop_front();
			}
			else
			{
				cin >> num;
				for (iter = d.begin(); iter != d.end(); iter++)
				{
					if (*iter == num)
					{
						d.erase(iter);
						break;
					}
				}
				d.push_front(num);
			}
		}

	}

	system("pause");
	return 0;
}