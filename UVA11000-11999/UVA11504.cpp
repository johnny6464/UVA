#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

struct Node {
	int order = 0;
	int low = 0;
	set<int> neighbors;
	set<int> parents;
};

bool inStack(vector<int>& sequence, int target) {
	for (auto iter = sequence.begin(); iter != sequence.end(); iter++) {
		if (*iter == target) {
			return true;
		}
	}
	return false;
}

bool hasZeroIn(map<int, Node>& relation, set<int>& s) {
	bool in = false;
	for (auto iter = s.begin(); iter != s.end() && !in; iter++) {
		for (auto iter1 = relation[*iter].parents.begin(); iter1 != relation[*iter].parents.end(); iter1++) {
			if (s.find(*iter1) == s.end()) {
				in = true;
				break;
			}
		}
	}
	return !in;
}

void tarjan(map<int, Node>& relation, vector<int>& sequence, int now, int& order, int& head) {
	relation[now].order = relation[now].low = ++order;
	sequence.push_back(now);

	for (auto iter = relation[now].neighbors.begin(); iter != relation[now].neighbors.end(); iter++) {
		if (relation[*iter].order != 0 && inStack(sequence, *iter)) {
			relation[now].low = relation[now].low < relation[*iter].order ? relation[now].low : relation[*iter].order;
		}
		if (relation[*iter].order == 0) {
			tarjan(relation, sequence, *iter, order, head);
			relation[now].low = relation[now].low < relation[*iter].low ? relation[now].low : relation[*iter].low;
		}
	}

	if (relation[now].order == relation[now].low) {
		set<int> s;
		while (sequence.back() != now) {
			s.insert(sequence.back());
			sequence.pop_back();
		}
		s.insert(sequence.back());
		sequence.pop_back();
		
		if (hasZeroIn(relation, s)) {
			head++;
		}
	}
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int vNum, eNum, src, dst;
		cin >> vNum >> eNum;

		map<int, Node> relation;
		for (int i = 1; i <= vNum; i++) {
			relation[i] = Node();
		}
		for (int i = 0; i < eNum; i++) {
			cin >> src >> dst;
			relation[src].neighbors.insert(dst);
			relation[dst].parents.insert(src);
		}

		int order = 0, head = 0;
		vector<int>sequence;
		for (auto iter = relation.begin(); iter != relation.end(); iter++) {
			if (iter->second.order == 0) {
				tarjan(relation, sequence, iter->first, order, head);
			}
		}
		cout << head << endl;
	}
	return 0;
}