#include<iostream>
#include<iomanip>
using namespace std;

struct Point
{
	double x = 0.0;
	double y = 0.0;
};

int main()
{
	Point p1, p2, p3, p4;
	while (cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y)
	{
		Point p;
		if (p1.x == p2.x && p1.y == p2.y)
		{
			p.x = p3.x + p4.x - p1.x;
			p.y = p3.y + p4.y - p1.y;
		}
		else if (p1.x == p3.x && p1.y == p3.y)
		{
			p.x = p2.x + p4.x - p1.x;
			p.y = p2.y + p4.y - p1.y;
		}
		else if (p1.x == p4.x && p1.y == p4.y)
		{
			p.x = p2.x + p3.x - p1.x;
			p.y = p2.y + p3.y - p1.y;
		}
		else if (p2.x == p3.x && p2.y == p3.y)
		{
			p.x = p1.x + p4.x - p2.x;
			p.y = p1.y + p4.y - p2.y;
		}
		else if (p2.x == p4.x && p2.y == p4.y)
		{
			p.x = p1.x + p3.x - p2.x;
			p.y = p1.y + p3.y - p2.y;
		}
		else if (p3.x == p4.x && p3.y == p4.y)
		{
			p.x = p1.x + p2.x - p3.x;
			p.y = p1.y + p2.y - p3.y;
		}

		cout << fixed << setprecision(3) << p.x << " " << p.y << endl;
	}


	system("pause");
	return 0;
}