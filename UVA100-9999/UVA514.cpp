#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main()
{
	int trains = 0;
	while (cin >> trains)
	{
		if (trains == 0)
		{
			break;
		}
		while (true)
		{
			stack<int> s;
			vector<int> v;
			bool end = 0;
			for (int i = 0; i < trains; i++)
			{
				int num = 0;
				cin >> num;
				if (num == 0)
				{
					end = 1;
					break;
				}

				v.push_back(num);
			}

			if (end)
			{
				cout << endl;
				break;
			}

			bool order = 1;
			int train = 1;
			int index = 0;

			while (train < trains + 1)
			{
				s.push(train++);
				while (!s.empty() && s.top() == v[index])
				{
					s.pop();
					index++;
				}
			}
			if (s.empty())
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}

	system("pause");
	return 0;
}