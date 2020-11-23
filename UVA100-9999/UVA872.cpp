#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

struct Node {
	bool isVisited = false;
	set<char> parent;
};

void backtrack(map<char, Node>& relation, vector<char>& sequence, char now, bool& isCycle) {
	if (sequence.size() == relation.size()) {
		for (auto iter = sequence.begin(); iter != sequence.end() - 1; iter++) {
			cout << *iter << " ";
		}
		cout << *(sequence.end() - 1) << endl;
		return;
	}

	bool hasPath = false;
	for (auto iter = relation.begin(); iter != relation.end(); iter++) {
		if (!relation[iter->first].isVisited) {
			bool available = !isCycle;
			for (auto iter1 = iter->second.parent.begin(); iter1 != iter->second.parent.end() && available; iter1++) {
				if (!relation[*iter1].isVisited) {
					available = false;
				}
			}
			if (available) {
				hasPath = true;
				relation[iter->first].isVisited = true;
				sequence.push_back(iter->first);
				backtrack(relation, sequence, iter->first, isCycle);
				sequence.pop_back();
				relation[iter->first].isVisited = false;
			}
		}
	}
	if (!hasPath) {
		isCycle = true;
	}
}

void topologicalSort(map<char, Node>& relation) {
	bool isCycle = false;
	bool deadlock = true;
	vector<char> sequence;
	for (auto iter = relation.begin(); iter != relation.end() && !isCycle; iter++) {
		if (iter->second.parent.size() == 0) {
			deadlock = false;
			relation[iter->first].isVisited = true;
			sequence.push_back(iter->first);
			backtrack(relation, sequence, iter->first, isCycle);
			sequence.pop_back();
			relation[iter->first].isVisited = false;
		}
	}
	if (isCycle || deadlock) {
		cout << "NO" << endl;
	}
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		while (cin.peek() == '\n') {
			cin.get();
		}
		map<char, Node> relation;
		char c;
		string rule;
		while (cin.peek() != '\n') {
			cin >> c;
			relation[c] = Node();
		}
		cin.get();
		while (cin.peek() != '\n') {
			cin >> rule;
			relation[rule[2]].parent.insert(rule[0]);
		}
		topologicalSort(relation);
		if (cases) {
			cout << endl;
		}
	}
	return 0;
}