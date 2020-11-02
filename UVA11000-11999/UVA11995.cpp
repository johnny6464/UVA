#include<iostream>
#include<bitset>
#include<stack>
#include<queue>
using namespace std;

int main() {
	int count;
	while (cin >> count) {
		bitset<3> available;
		available.set();

		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;

		int op, num;
		while (count--) {
			cin >> op >> num;
			if (op == 1) {
				s.push(num);
				q.push(num);
				pq.push(num);
			}
			else {
				if (!s.empty() && s.top() == num) {
					s.pop();
				}
				else {
					available.set(0, false);
				}

				if (!q.empty() && q.front() == num) {
					q.pop();
				}
				else {
					available.set(1, false);
				}

				if (!pq.empty() && pq.top() == num) {
					pq.pop();
				}
				else {
					available.set(2, false);
				}
			}
		}

		
		if (available.count() > 1) {
			cout << "not sure" << endl;
		}
		else if (available.count() == 0) {
			cout << "impossible" << endl;
		}
		else {
			if (available[0]) {
				cout << "stack" << endl;
			}
			else if (available[1]) {
				cout << "queue" << endl;
			}
			else {
				cout << "priority queue" << endl;
			}
		}
	}

	return 0;
}