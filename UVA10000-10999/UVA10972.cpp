#include<iostream>
#include<stack>
#include<set>
#include<map>
using namespace std;

struct Node {
	int order = 0;
	int low = 0;
	set<int> neighbor;
};

void tarjan(map<int, Node>& relation, int now, int parent, int& order) {
	relation[now].order = relation[now].low = ++order;

	for (auto iter = relation[now].neighbor.begin(); iter != relation[now].neighbor.end(); iter++) {
		if (*iter != parent) {
			if (relation[*iter].order != 0) {
				relation[now].low = relation[now].low < relation[*iter].order ? relation[now].low : relation[*iter].order;
			}
			if (relation[*iter].order == 0) {
				tarjan(relation, *iter, now, order);
				relation[now].low = relation[now].low < relation[*iter].low ? relation[now].low : relation[*iter].low;
			}
		}
	}
}

int main() {
	int nodes, edges;
	while (cin >> nodes >> edges) {
		map<int, Node> relation;
		int src, dst;
		for (int i = 1; i <= nodes; i++) {
			relation[i] = Node();
		}

		while (edges--) {
			cin >> src >> dst;
			relation[src].neighbor.insert(dst);
			relation[dst].neighbor.insert(src);
		}

		int order = 0;
		for (auto iter = relation.begin(); iter != relation.end(); iter++) {
			if (iter->second.order == 0) {
				tarjan(relation, iter->first, 0, order);
			}
		}

		map<int, int> degree;
		for (auto iter = relation.begin(); iter != relation.end(); iter++) {
			int ccId = iter->second.low;
			if (degree.find(ccId) == degree.end()) {
				degree[ccId] = 0;
			}
			for (auto iter1 = iter->second.neighbor.begin(); iter1 != iter->second.neighbor.end(); iter1++) {
				if (ccId != relation[*iter1].low) {
					degree[ccId]++;
				}
			}
		}
		if (degree.size() == 1) {
			cout << 0 << endl;
			continue;
		}

		int leaves = 0, alone = 0;
		for (auto iter = degree.begin(); iter != degree.end(); iter++) {
			if (iter->second == 0) {
				alone++;
			}
			if (iter->second == 1) {
				leaves++;
			}
		}
		cout << (leaves + 1) / 2 + alone << endl;
	}
	return 0;
}