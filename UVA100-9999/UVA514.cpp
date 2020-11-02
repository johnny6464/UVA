#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int numOfTrain;
	while (cin >> numOfTrain && numOfTrain) {
		while (true) {
			stack<int> s;
			vector<int> order;
			int train;
			
			for (int i = 1; i <= numOfTrain; i++) {
				cin >> train;
				if (train == 0) {
					break;
				}
				order.push_back(train);
			}

			if (order.empty()) {
				break;
			}

			int departure = 0;
			for (int i = 1; i <= numOfTrain; i++) {
				s.push(i);
				while (!s.empty() && s.top() == order[departure]) {
					s.pop();
					departure++;
				}
			}

			if (s.empty()) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
		cout << endl;
	}

	return 0;
}