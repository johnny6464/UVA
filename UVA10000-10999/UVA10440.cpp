#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

void load(queue<int>& cars, int num, int& currentTime, int t) {
	int loaded = 0;
	while (++loaded < num) {
		cars.pop();
	}
	currentTime = currentTime > cars.front() ? currentTime : cars.front();
	cars.pop();
	currentTime += 2 * t;
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int n, t, m;
		cin >> n >> t >> m;

		queue<int> cars;
		int time;
		for (int i = 0; i < m; i++) {
			cin >> time;
			cars.push(time);
		}
		
		int currentTime = 0;
		int prev = cars.size() % n;
		if (prev != 0) {
			load(cars, prev, currentTime, t);
		}
		while (!cars.empty()) {
			load(cars, n, currentTime, t);
		}
		cout << currentTime - t << " " << ceil(double(m) / double(n)) << endl;
	}
	return 0;
}