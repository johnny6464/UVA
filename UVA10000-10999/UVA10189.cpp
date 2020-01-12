#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int row = 0, col = 0;
	int counter = 0;
	while (cin >> row >> col)
	{
		if (row == 0 && col == 0)
		{
			break;
		}

		if (counter++ != 0)
		{
			cout << endl;
		}

		vector<vector<int>> matrix;
		for (int i = 0; i < row + 2; i++)
		{
			vector<int> v(col + 2, -9);
			matrix.push_back(v);
		}

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				matrix[i][j] = 0;
			}
		}

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				char c;
				cin >> c;
				if (c == '*')
				{
					matrix[i][j] = -9;
					for (int k = i - 1; k <= i + 1; k++)
					{
						for (int l = j - 1; l <= j + 1; l++)
						{
							matrix[k][l] += 1;
						}
					}
				}
			}
		}

		cout << "Field #" << counter << ":" << endl;

		for (int i = 1; i <= row; i++)
		{
			for (int j = 1; j <= col; j++)
			{
				if (matrix[i][j] >= 0)
				{
					cout << matrix[i][j];
				}
				else
				{
					cout << "*";
				}
			}
			cout << endl;
		}
	}

	system("pause");
	return 0;
}