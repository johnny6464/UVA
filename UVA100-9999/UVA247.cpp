#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;

struct Node {
	int order = 0;
	int low = 0;
	set<string> neighbors;
};

bool inStack(vector<string>& sequence, string target) {
	for (auto iter = sequence.begin(); iter != sequence.end(); iter++) {
		if (*iter == target) {
			return true;
		}
	}
	return false;
}

void tarjan(map<string, Node>& relation, vector<string>& sequence, vector<set<string>>& scc, string now, int& order) {
	relation[now].order = relation[now].low = ++order;
	sequence.push_back(now);

	for (auto iter = relation[now].neighbors.begin(); iter != relation[now].neighbors.end(); iter++) {
		if (relation[*iter].order != 0 && inStack(sequence, *iter)) {
			relation[now].low = relation[now].low < relation[*iter].order ? relation[now].low : relation[*iter].order;
		}
		if (relation[*iter].order == 0) {
			tarjan(relation, sequence, scc, *iter, order);
			relation[now].low = relation[now].low < relation[*iter].low ? relation[now].low : relation[*iter].low;
		}
	}

	if (relation[now].order == relation[now].low) {
		set<string> s;
		while (sequence.back() != now) {
			s.insert(sequence.back());
			sequence.pop_back();
		}
		s.insert(sequence.back());
		sequence.pop_back();
		scc.push_back(s);
	}
}

int main() {
	int vNum, eNum, cases = 1;
	while (cin >> vNum >> eNum && (vNum || eNum)) {
		string src, dst;
		map<string, Node> relation;
		for (int i = 0; i < eNum; i++) {
			cin >> src >> dst;
			relation[src].neighbors.insert(dst);
		}
		int order = 0;
		vector<string>sequence;
		vector<set<string>> scc;
		for (auto iter = relation.begin(); iter != relation.end(); iter++) {
			if (iter->second.order == 0) {
				tarjan(relation, sequence, scc, iter->first, order);
			}
		}
		
		if (cases != 1) {
			cout << endl;
		}
		cout << "Calling circles for data set " << cases++ << ":" << endl;
		for (auto iter = scc.begin(); iter != scc.end(); iter++) {
			cout << *(iter->begin());
			for (auto iter1 = ++iter->begin(); iter1 != iter->end(); iter1++) {
				cout << ", " << *iter1;
			}
			cout << endl;
		}
	}
	return 0;
}