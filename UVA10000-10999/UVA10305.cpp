#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

struct Node {
	bool isVisited = false;
	set<int> childern;
};

void topologicalSort(map<int, Node>& relation, vector<int>& sequence, int now) {
	relation[now].isVisited = true;
	for (auto iter = relation[now].childern.begin(); iter != relation[now].childern.end(); iter++) {
		if (!relation[*iter].isVisited) {
			topologicalSort(relation, sequence, *iter);
		}
	}
	sequence.push_back(now);
}

int main() {
	int tasks, rules;
	while (cin >> tasks >> rules && tasks) {
		map<int, Node> relation;
		for (int i = 1; i <= tasks; i++) {
			relation[i] = Node();
		}
		int src, dst;
		for (int i = 0; i < rules; i++) {
			cin >> src >> dst;
			relation[src].childern.insert(dst);
		}

		vector<int> sequence;
		for (auto iter = relation.begin(); iter != relation.end(); iter++) {
			if (!relation[iter->first].isVisited) {
				topologicalSort(relation, sequence, iter->first);
			}
		}

		for (int i = sequence.size() - 1; i > 0; i--) {
			cout << sequence[i] << " ";
		}
		cout << sequence[0] << endl;
	}
	return 0;
}