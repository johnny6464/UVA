#include<iostream>
#include<stack>
#include<queue>
#include<vector>
using namespace std;


int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int N, S, Q, time = 0;
		vector<queue<int>> stations;

		cin >> N >> S >> Q;
		for (int i = 0; i < N; i++) {
			int cargos;
			cin >> cargos;

			queue<int> q;
			for (int j = 0; j < cargos; j++) {
				int dest;
				cin >> dest;
				q.push(dest);
			}
			stations.push_back(q);
		}

		stack<int> s;
		int now = 1;
		bool cont = true;
		while (cont) {
			if (now > N) {
				now = 1;
			}
			while (!s.empty()) {
				if (s.top() == now) {
					s.pop();
					time++;
				}
				else if (stations[now - 1].size() < Q) {
					stations[now - 1].push(s.top());
					s.pop();
					time++;
				}
				else {
					break;
				}
			}

			while (!stations[now - 1].empty() && s.size() < S) {
				s.push(stations[now - 1].front());
				stations[now - 1].pop();
				time++;
			}

			cont = false;
			if (!s.empty()) {
				cont = true;
			}
			for (auto iter = stations.begin(); iter != stations.end(); iter++) {
				if (iter->size() != 0) {
					cont = true;
					break;
				}
			}
			if (cont) {
				time += 2;
				now++;
			}
		}
		cout << time << endl;
	}
	return 0;
}