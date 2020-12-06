#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

struct Node {
	int order = 0;
	int low = 0;
	set<int> neighbors;
};

bool inStack(vector<int>& sequence, int target) {
	for (auto iter = sequence.begin(); iter != sequence.end(); iter++) {
		if (*iter == target) {
			return true;
		}
	}
	return false;
}

void tarjan(map<int, Node>& relation, vector<int>& sequence, int now, int& order, int& sccCount) {
	relation[now].order = relation[now].low = ++order;
	sequence.push_back(now);

	for (auto iter = relation[now].neighbors.begin(); iter != relation[now].neighbors.end(); iter++) {
		if (relation[*iter].order != 0 && inStack(sequence, *iter)) {
			relation[now].low = relation[now].low < relation[*iter].order ? relation[now].low : relation[*iter].order;
		}
		if (relation[*iter].order == 0) {
			tarjan(relation, sequence, *iter, order, sccCount);
			relation[now].low = relation[now].low < relation[*iter].low ? relation[now].low : relation[*iter].low;
		}
	}

	if (relation[now].order == relation[now].low) {
		sccCount++;
		while (sequence.back() != now) {
			sequence.pop_back();
		}
		sequence.pop_back();
	}
}

int main() {
	int vNum, eNum;
	while (cin >> vNum >> eNum && vNum && eNum) {
		map<int, Node> relation;
		for (int i = 1; i <= vNum; i++) {
			relation[i] = Node();
		}

		int src, dst, p;
		for (int i = 0; i < eNum; i++) {
			cin >> src >> dst >> p;
			relation[src].neighbors.insert(dst);
			if (p == 2) {
				relation[dst].neighbors.insert(src);
			}
		}

		int order = 0, head = 0, sccCount = 0;
		vector<int>sequence;
		tarjan(relation, sequence, 1, order, sccCount);

		if (order < relation.size() || sccCount > 1) {
			cout << 0 << endl;
		}
		else {
			cout << 1 << endl;
		}
	}
	return 0;
}