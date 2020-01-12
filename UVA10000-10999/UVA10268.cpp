#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

typedef long long LL;

int main()
{
	int x = 0;
	while (cin >> x)
	{
		stringstream ss;
		string s;
		vector<LL> v;

		cin.ignore();
		getline(cin, s);
		ss << s;

		LL temp = 0;
		while (ss >> temp)
		{
			v.push_back(temp);
		}

		LL sum = 0, coef = 1, power = 1;
		for (LL i = v.size() - 2; i >= 0; i--)
		{
			sum += v[i] * coef++ * power;
			power *= x;
		}

		cout << sum << endl;
	}

	system("pause");
	return 0;
}