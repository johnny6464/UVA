#include<iostream>
#include<iomanip>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int cases = 0;
	cin >> cases;
	while (cases--)
	{
		int players = 0;
		double p = 0;
		int target = 0;
		cin >> players >> p >> target;
		
		if (p == 0)
		{
			cout << fixed << setprecision(4) << p << endl;
			continue;
		}

		double q = 1 - p;
		double common_ratio = pow(q, players);
		double first_term = pow(q, target - 1) * p;
		double ans = first_term * (1 - pow(common_ratio, 50)) / (1 - common_ratio);
		
		cout << fixed << setprecision(4) << ans << endl;
	}

	system("pause");
	return 0;
}