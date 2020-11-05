#include<iostream>
#include<queue>
using namespace std;

struct Car {
	int time = 0;
	int id = 0;
	Car(int time, int id) {
		this->time = time;
		this->id = id;
	}
};

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int n, t, m;
		cin >> n >> t >> m;

		queue<Car> left, right;
		vector<int> v(m, 0);
		int time;
		string side;
		for (int i = 0; i < m; i++) {
			cin >> time >> side;
			if (side == "left") {
				left.push(Car(time, i));
			}
			else {
				right.push(Car(time, i));
			}
		}

		int currentTime = 0;
		bool isLeft = true;
		while (!left.empty() || !right.empty()) {
			int count = 0;
			if (isLeft) {
				if (left.empty() || !right.empty() && left.front().time > currentTime && right.front().time < left.front().time) {
					currentTime = right.front().time > currentTime ? right.front().time : currentTime;
				}
				else {
					currentTime = left.front().time > currentTime ? left.front().time : currentTime;
					while (!left.empty() && left.front().time <= currentTime && ++count <= n) {
						v[left.front().id] = currentTime + t;
						left.pop();
					}
				}
			}
			else {
				if (right.empty() || !left.empty() && right.front().time > currentTime && left.front().time < right.front().time) {
					currentTime = left.front().time > currentTime ? left.front().time : currentTime;
				}
				else {
					currentTime = right.front().time > currentTime ? right.front().time : currentTime;
					while (!right.empty() && right.front().time <= currentTime && ++count <= n) {
						v[right.front().id] = currentTime + t;
						right.pop();
					}
				}
			}
			currentTime += t;
			isLeft = !isLeft;
		}

		for (auto iter = v.begin(); iter != v.end(); iter++) {
			cout << *iter << endl;
		}

		if (cases) {
			cout << endl;
		}
	}
	return 0;
}