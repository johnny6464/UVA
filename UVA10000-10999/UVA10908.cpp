#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		int r = 0, c = 0, q = 0;
		cin >> r >> c >> q;
		cout << r << " " << c << " " << q << endl;

		vector<vector<char>> matrix;
		for (int i = 0; i < r; i++)
		{
			vector<char> v;
			for (int j = 0; j < c; j++)
			{
				char c;
				cin >> c;
				v.push_back(c);
			}
			matrix.push_back(v);
		}

		while (q--)
		{
			int x = 0, y = 0;
			cin >> x >> y;

			char now = matrix[x][y];
			int max = 1;
			for (int i = 1; i < 1000; i++)
			{
				if ((x + i > r - 1) 
					|| (x - i < 0)
					|| (y + i > c - 1) 
					|| (y - i < 0))
				{
					break;
				}

				bool add = 1;
				for (int j = x - i; j <= x + i; j++)
				{
					for (int k = y - i; k <= y + i; k++)
					{
						if (matrix[j][k] != now)
						{
							add = 0;
							break;
						}
					}
					if (!add)
					{
						break;
					}
				}

				if (add)
				{
					max += 2;
				}
				else
				{
					break;
				}
			}


			cout << max << endl;
		}
	}

	system("pause");
	return 0;
}