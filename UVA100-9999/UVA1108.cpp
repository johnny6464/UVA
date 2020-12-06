#include<iostream>
#include<stack>
#include<set>
#include<map>
using namespace std;

struct Node {
	int order = 0;
	int low = 0;
	bool critical = false;
	set<int> childern;
};

void tarjan(map<int, Node>& relation, stack<int>& sequence, map<int, set<int>>& cc, int now, int parent, int& order, int& id) {
	relation[now].order = relation[now].low = ++order;

	bool isCritical = false;
	int children = 0;
	for (auto iter = relation[now].childern.begin(); iter != relation[now].childern.end(); iter++) {
		if (*iter != parent) {
			if (relation[*iter].order != 0) {
				relation[now].low = relation[now].low < relation[*iter].order ? relation[now].low : relation[*iter].order;
			}
			if (relation[*iter].order == 0) {
				sequence.push(*iter);
				tarjan(relation, sequence, cc, *iter, now, order, id);
				relation[now].low = relation[now].low < relation[*iter].low ? relation[now].low : relation[*iter].low;

				children++;
				if (relation[*iter].low >= relation[now].order) {
					isCritical = true;

					++id;
					while (sequence.top() != *iter) {
						cc[id].insert(sequence.top());
						sequence.pop();
					}
					cc[id].insert(*iter);
					cc[id].insert(now);
					sequence.pop();
				}
			}
		}
	}
	if (isCritical && (now != 1 || children > 1)) {
		relation[now].critical = true;
	}
}

int main() {
	int rules;
	int cases = 0;
	while (cin >> rules && rules) {
		map<int, Node> relation;
		int src, dst;
		while (rules--) {
			cin >> src >> dst;
			relation[src].childern.insert(dst);
			relation[dst].childern.insert(src);
		}

		int id = 0, order = 0;
		stack<int> sequence;
		map<int, set<int>> cc;
		tarjan(relation, sequence, cc, 1, 0, order, id);

		long long shafts = 0, ways = 1;
		if (id == 1) {
			shafts = 2;
			ways = relation.size() * (relation.size() - 1) / 2;
		}
		else {
			for (int i = 1; i <= cc.size(); i++) {
				long long critical = 0, size = cc[i].size();
				for (auto iter = cc[i].begin(); iter != cc[i].end(); iter++) {
					if (relation[*iter].critical) {
						critical++;
					}
				}
				if (critical == 1) {
					shafts++;
					ways *= size - 1;
				}
			}
		}
		cout << "Case " << ++cases << ": " << shafts << " " << ways << endl;
	}
	return 0;
}