#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

void bfs(vector<set<int>>& config, vector<vector<pair<bool, int>>>& distance, int nodes) {
	for (int i = 1; i <= nodes; i++) {
		queue<pair<int, int>> q;
		q.push(pair<int, int>(i, 0));
		while (!q.empty()) {
			pair<int, int> p = q.front();
			q.pop();

			if (distance[i][p.first].first) {
				continue;
			}

			distance[i][p.first].first = true;
			distance[i][p.first].second = p.second;
			for (auto iter = config[p.first].begin(); iter != config[p.first].end(); iter++) {
				q.push(pair<int, int>(*iter, p.second + 1));
			}
		}
	}
}


int main() {
	int nodes, A, B, dst;
	while (cin >> nodes && nodes) {
		vector<set<int>> oldConfig(nodes + 1, set<int>());
		vector<set<int>> newConfig(nodes + 1, set<int>());
		vector<vector<pair<bool, int>>> oldDistance(nodes + 1, vector<pair<bool, int>>(nodes + 1, pair<bool, int>(false, -1)));
		vector<vector<pair<bool, int>>>	newDistance(nodes + 1, vector<pair<bool, int>>(nodes + 1, pair<bool, int>(false, -1)));
		for (int i = 1; i <= nodes; i++) {
			cin >> dst;
			while (cin.peek() != '\n') {
				cin >> dst;
				oldConfig[i].insert(dst);
			}
		}
		for (int i = 1; i <= nodes; i++) {
			cin >> dst;
			while (cin.peek() != '\n') {
				cin >> dst;
				newConfig[i].insert(dst);
			}
		}
		cin >> A >> B;

		bfs(oldConfig, oldDistance, nodes);
		bfs(newConfig, newDistance, nodes);

		bool satisfy = true;
		for (int i = 1; i <= nodes && satisfy; i++) {
			for (int j = 1; j <= nodes; j++) {
				if (oldDistance[i][j].second * A + B < newDistance[i][j].second || newDistance[i][j].second == -1) {
					satisfy = false;
					break;
				}
			}
		}
		if (satisfy) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}