#include<iostream>
#include<queue>
#include<map>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int jobs, myJob;
		cin >> jobs >> myJob;

		int job;
		queue<int> q;
		map<int, int> priority;
		for (int i = 0; i < jobs; i++) {
			cin >> job;
			q.push(job);
			priority[job]++;
		}

		int time = 0;
		while (true) {
			if (priority.rbegin()->first > q.front()) {
				q.push(q.front());
				q.pop();
				myJob--;
				if (myJob < 0) {
					myJob = q.size() - 1;
				}
			}
			else {
				if (priority[q.front()] == 1) {
					priority.erase(q.front());
				}
				else {
					priority[q.front()]--;
				}
				q.pop();
				time++;
				if (myJob == 0) {
					break;
				}
				else {
					myJob--;
				}
			}
		}
		cout << time << endl;
	}
	return 0;
}