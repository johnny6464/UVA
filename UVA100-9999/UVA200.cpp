#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

struct Node {
	int discover = 0;
	int finish = 0;
	set<char> neighbors;
};

void topologicalSort(map<char, Node>& relation, char now, int& order, vector<char>& sequence) {
	relation[now].discover = ++order;
	for (auto iter = relation[now].neighbors.begin(); iter != relation[now].neighbors.end(); iter++) {
		if (relation[*iter].discover == 0) {
			topologicalSort(relation, *iter, order, sequence);
		}
	}
	relation[now].finish = ++order;
	sequence.push_back(now);
}


int main() {
	string str;
	vector<string> index;
	map<char, Node> relation;
	while (cin >> str && str != "#") {
		index.push_back(str);
	}
	for (int i = 0; i < index.size() - 1; i++) {
		int size = index[i].size() < index[i + 1].size() ? index[i].size() : index[i + 1].size();
		for (int j = 0; j < size; j++) {
			if (index[i][j] != index[i + 1][j]) {
				relation[index[i][j]].neighbors.insert(index[i + 1][j]);
				break;
			}
		}
	}

	int order = 0;
	vector<char> sequence;
	for (auto iter = relation.begin(); iter != relation.end(); iter++) {
		if (iter->second.discover == 0) {
			topologicalSort(relation, iter->first, order, sequence);
		}
	}

	while (!sequence.empty()) {
		cout << sequence.back();
		sequence.pop_back();
	}
	cout << endl;
	return 0;
}