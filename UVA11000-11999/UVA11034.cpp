#include<iostream>
#include<queue>
using namespace std;


int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int ferry, cars;
		cin >> ferry >> cars;
		ferry *= 100;

		queue<int> left;
		queue<int> right;
		int length;
		string direction;
		while (cars--) {
			cin >> length >> direction;
			if (direction == "left") {
				left.push(length);
			}
			else {
				right.push(length);
			}
		}

		int times = 0;
		bool isLeft = true;
		while (!left.empty() || !right.empty()) {
			int loaded = 0;
			if (isLeft) {
				while (!left.empty() && left.front() + loaded <= ferry) {
					loaded += left.front();
					left.pop();
				}
			}
			else {
				while (!right.empty() && right.front() + loaded <= ferry) {
					loaded += right.front();
					right.pop();
				}
			}
			times++;
			isLeft = !isLeft;
		}
		cout << times << endl;
	}
	return 0;
}