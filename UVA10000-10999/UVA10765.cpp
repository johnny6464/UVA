#include<iostream>
#include<map>
#include<set>
using namespace std;

struct Station {
	int order = -1;
	int low = -1;
	int pValue = 1;
	set<int> neightbor;
};

void dfsTree(map<int, Station>& vertices, int now, int parent, int order) {
	vertices[now].order = vertices[now].low = order;

	bool isCritical = false;
	for (auto iter = vertices[now].neightbor.begin(); iter != vertices[now].neightbor.end(); iter++) {
		if (*iter != parent) {
			if (vertices[*iter].order != -1) {
				vertices[now].low = vertices[now].low < vertices[*iter].order ? vertices[now].low : vertices[*iter].order;
			}
			if (vertices[*iter].order == -1) {
				dfsTree(vertices, *iter, now, order + 1);
				vertices[now].low = vertices[now].low < vertices[*iter].low ? vertices[now].low : vertices[*iter].low;

				if (vertices[*iter].low >= vertices[now].order) {
					vertices[now].pValue++;
				}
			}
		}
	}
}

int main() {
	int stations, bomb;
	while (cin >> stations >> bomb && stations && bomb) {
		map<int, Station> vertices;
		int src, dst;
		while (cin >> src >> dst && src != -1 && dst != -1) {
			vertices[src].neightbor.insert(dst);
			vertices[dst].neightbor.insert(src);
		}
		vertices[0].pValue = 0;

		dfsTree(vertices, 0, -1, 0);
		int maxPValue = 0;
		for (auto iter = vertices.begin(); iter != vertices.end(); iter++) {
			maxPValue = maxPValue > iter->second.pValue ? maxPValue : iter->second.pValue;
		}

		while (bomb > 0) {
			for (auto iter = vertices.begin(); iter != vertices.end(); iter++) {
				if (iter->second.pValue == maxPValue) {
					cout << iter->first << " " << iter->second.pValue << endl;
					bomb--;
				}
				if (!bomb) {
					break;
				}
			}
			maxPValue--;
		}
		cout << endl;
	}
	return 0;
}