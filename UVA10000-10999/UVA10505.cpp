#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct Node {
	bool visit;
	bool color;
	set<int> neighbors;
};

bool dfs(vector<Node>& relation, int now, bool color, int& black, int& white) {
	relation[now].color = color;
	relation[now].visit = true;
	if (color) {
		black++;
	}
	else {
		white++;
	}

	bool bipartite = true;
	for (auto iter = relation[now].neighbors.begin(); iter != relation[now].neighbors.end(); iter++) {
		if (!relation[*iter].visit) {
			if (!dfs(relation, *iter, !color, black, white)) {
				bipartite = false;
			}
		}
		else if (relation[*iter].color == color) {
			bipartite = false;
		}
	}
	return bipartite;
}


int main() {
	int cases, num;
	cin >> cases;
	while (cases--) {
		cin >> num;
		vector<Node> relation(num + 1, Node{ false, false, set<int>() });
		int n;
		for (int i = 1; i <= num; i++) {
			cin >> n;
			int id;
			while (n--) {
				cin >> id;
				if (id >= 1 && id <= num) {
					relation[i].neighbors.insert(id);
					relation[id].neighbors.insert(i);
				}
			}
		}

		int max = 0;
		for (int i = 1; i <= num; i++) {
			int black = 0, white = 0;
			if (relation[i].neighbors.empty()) {
				max++;
			}
			else if (!relation[i].visit && dfs(relation, i, true, black, white)) {
				max += black > white ? black : white;
			}
		}
		cout << max << endl;
	}
	return 0;
}