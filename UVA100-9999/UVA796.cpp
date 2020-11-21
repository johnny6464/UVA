#include<iostream>
#include<map>
#include<set>
using namespace std;

struct Vertex {
	int order = -1;
	int low = -1;
	set<int> neightbor;
};

void dfsTree(map<int, Vertex>& vertices, int now, int parent, int order, map<int, set<int>>& criticalLink) {
	vertices[now].order = vertices[now].low = order;

	bool isCritical = false;
	for (auto iter = vertices[now].neightbor.begin(); iter != vertices[now].neightbor.end(); iter++) {
		if (*iter != parent) {
			if (vertices[*iter].order != -1) {
				vertices[now].low = vertices[now].low < vertices[*iter].order ? vertices[now].low : vertices[*iter].order;
			}
			if (vertices[*iter].order == -1) {
				dfsTree(vertices, *iter, now, order + 1, criticalLink);
				vertices[now].low = vertices[now].low < vertices[*iter].low ? vertices[now].low : vertices[*iter].low;

				if (vertices[*iter].low > vertices[now].order) {
					if (now < *iter) {
						criticalLink[now].insert(*iter);
					}
					else {
						criticalLink[*iter].insert(now);
					}
				}
			}
		}
	}
}

int main() {
	int places;
	while (cin >> places) {
		map<int, Vertex> vertices;
		for (int i = 0; i < places; i++) {
			int src, dst;
			string useless;
			cin >> src >> useless;
			while (cin.peek() != '\n') {
				cin >> dst;
				vertices[src].neightbor.insert(dst);
				vertices[dst].neightbor.insert(src);
			}
		}

		map<int, set<int>> criticalLink;
		for (int i = 0; i < places; i++) {
			if (vertices[i].order == -1) {
				dfsTree(vertices, i, -1, 0, criticalLink);
			}
		}

		int critical = 0;
		for (auto iter = criticalLink.begin(); iter != criticalLink.end(); iter++) {
			critical += iter->second.size();
		}
		cout << critical << " critical links" << endl;
		for (auto iter = criticalLink.begin(); iter != criticalLink.end(); iter++) {
			for (auto iter1 = iter->second.begin(); iter1 != iter->second.end(); iter1++) {
				cout << iter->first << " - " << *iter1 << endl;
			}
		}
		cout << endl;
	}
	return 0;
}