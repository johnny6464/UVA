#include<iostream>
#include<vector>
using namespace std;

typedef long long LL;

int main()
{
	int cases = 0;
	cin >> cases;

	int counter = 0;
	while (cases--)
	{
		bool sym = true;
		int dim = 0;
		cin.ignore(4);
		cin >> dim;

		vector<LL> matrix;
		for (int i = 0; i < dim; i++)
		{
			for (int j = 0; j < dim; j++)
			{
				LL num = 0;
				cin >> num;
				if (num < 0)
				{
					sym = false;
				}
				matrix.push_back(num);
			}
		}

		for (int i = 0; i < matrix.size() / 2; i++)
		{
			if (!sym)
			{
				break;
			}
			
			if (matrix[i] != matrix[matrix.size() - 1 - i])
			{
				sym = false;
				break;
			}
		}


		if (sym)
		{
			cout << "Test #" << ++counter << ": Symmetric." << endl;
		}
		else
		{
			cout << "Test #" << ++counter << ": Non-symmetric." << endl;
		}
	}

	system("pause");
	return 0;
}