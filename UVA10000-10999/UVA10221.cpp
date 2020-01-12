#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;

const double pi = 2 * acos(0);
const double radius = 6440;

int main()
{
	double d = 0.0, a = 0.0;
	string s;
	while (cin >> d >> a >> s)
	{
		if (s == "min")
		{
			a /= 60;
		}

		while (a > 360)
		{
			a -= 360;
		}

		if (a > 180)
		{
			a = 360 - a;
		}

		double arc = 2 * pi * (radius + d) * a / 360;
		double chord = 2 * (radius + d) * sin(pi * a / 360);

		cout << fixed << setprecision(6) << arc << " " << chord << endl;
	}

	system("pause");
	return 0;
}