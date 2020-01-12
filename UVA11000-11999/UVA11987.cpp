#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int nums = 0, cmds = 0;
	while (cin >> nums >> cmds)
	{
		int m[100001];

		vector<vector<int>> set;
		vector<int> offset;
		set.push_back(offset);
		for (int i = 1; i <= nums; i++)
		{
			vector<int> v(1, i);
			set.push_back(v);

			m[i] = i;
		}

		while (cmds--)
		{
			int cmd = 0, p = 0, q = 0;
			cin >> cmd;
			if (cmd == 1)
			{
				cin >> p >> q;

				int P = m[p];
				int Q = m[q];
				if (P == Q)
				{
					continue;
				}

				int clear = 0;
				int lenP = set[P].size();
				int lenQ = set[Q].size();
				if (lenP > lenQ)
				{
					clear = Q;
					for (int i = 0; i < lenQ; i++)
					{
						set[P].push_back(set[Q][i]);
						m[set[Q][i]] = m[p];
					}
				}
				else
				{
					clear = P;
					for (int i = 0; i < lenP; i++)
					{
						set[Q].push_back(set[P][i]);
						m[set[P][i]] = m[q];
					}
				}
				set[clear].clear();
			}
			else if (cmd == 2)
			{
				cin >> p >> q;

				int P = m[p];
				int Q = m[q];
				if (P == Q)
				{
					continue;
				}

				vector<int>::iterator i;
				for (i = set[P].begin(); i != set[P].end(); i++)
				{
					if (*i == p)
					{
						break;
					}
				}
				set[P].erase(i);
				set[Q].push_back(p);
				m[p] = m[q];
			}
			else if (cmd == 3)
			{
				cin >> p;

				int sum = 0;
				for (int i = 0; i < set[m[p]].size(); i++)
				{
					sum += set[m[p]][i];
				}
				cout << set[m[p]].size() << " " << sum << endl;
			}
		}
	}

	system("pause");
	return 0;
}