#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Point {
	int x;
	int y;
};

bool operator<(const Point& p1, const Point& p2) {
	if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
}

int main() {
	int cases, n, x, y;
	cin >> cases;
	while (cases--) {
		cin >> n;

		vector<Point> points;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			points.push_back(Point{ x, y });
		}

		sort(points.begin(), points.end());
		int meanX = points[0].x + points[n - 1].x, meanY = points[0].y + points[n - 1].y;
		bool symmetry = true;
		for (int i = 1; i < n / 2; i++) {
			if (points[i].x + points[n - i - 1].x != meanX || points[i].y + points[n - i - 1].y != meanY) {
				symmetry = false;
				break;
			}
		}

		if (n % 2 == 1) {
			if (points[n / 2].x * 2 != meanX || points[n / 2].y * 2 != meanY) {
				symmetry = false;
			}
		}

		if (symmetry) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
	return 0;
}