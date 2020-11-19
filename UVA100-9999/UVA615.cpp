#include<iostream>
#include<map>
#include<set>
using namespace std;

bool checkLoop(map<int, set<int>>& adj, set<int>& path, set<int>& hasGone, int now) {
	if (hasGone.find(now) != hasGone.end()) {
		return false;
	}

	hasGone.insert(now);
	path.insert(now);
	for (auto iter = adj[now].begin(); iter != adj[now].end(); iter++) {
		if (!checkLoop(adj, path, hasGone, *iter)) {
			return false;
		}
	}
	hasGone.erase(now);
	return true;
}

bool isTree(map<int, set<int>>& adj, map<int, int>& appears) {
	if (adj.empty()) {
		return true;
	}

	int rootCount = 0;
	int root = 0;
	for (auto iter = appears.begin(); iter != appears.end(); iter++) {
		if (iter->second > 1) {
			return false;
		}
		else if (iter->second == 0) {
			rootCount++;
			root = iter->first;
		}
	}
	if (rootCount != 1) {
		return false;
	}

	set<int> path, hasGone;
	if (!checkLoop(adj, path, hasGone, root) || path.size() != adj.size()) {
		return false;
	}
	return true;
}


int main() {
	int p1, p2;
	int count = 1;

	map<int, set<int>> adj;
	map<int, int> appears;
	while (cin >> p1 >> p2 && p1 != -1 && p2 != -1) {
		if (p1 == 0 && p2 == 0) {
			if (isTree(adj, appears)) {
				cout << "Case " << count++ << " is a tree." << endl;
			}
			else {
				cout << "Case " << count++ << " is not a tree." << endl;
			}
			adj.clear();
			appears.clear();
		}
		else {
			adj[p1].insert(p2);
			appears[p2]++;
			if (appears.find(p1) == appears.end()) {
				appears[p1] = 0;
			}
		}
	}
	return 0;
}