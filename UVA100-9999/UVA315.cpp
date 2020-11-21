#include<iostream>
#include<map>
#include<set>
using namespace std;

struct Vertex {
	int order = 0;
	int low = 0;
	set<int> neightbor;
};

void dfsTree(map<int, Vertex>& vertices, int now, int parent, int order, int& critical) {
	vertices[now].order = vertices[now].low = order;

	int children = 0;
	bool isCritical = false;
	for (auto iter = vertices[now].neightbor.begin(); iter != vertices[now].neightbor.end(); iter++) {
		if (*iter != parent) {
			if (vertices[*iter].order != 0) {
				vertices[now].low = vertices[now].low < vertices[*iter].order ? vertices[now].low : vertices[*iter].order;
			}
			if (vertices[*iter].order == 0) {
				dfsTree(vertices, *iter, now, order + 1, critical);
				vertices[now].low = vertices[now].low < vertices[*iter].low ? vertices[now].low : vertices[*iter].low;
				children++;

				if (vertices[*iter].low >= vertices[now].order) {
					isCritical = true;
				}
			}
		}
	}

	if (isCritical && (now != 1 || children > 1)) {
		critical++;
	}
}

int main() {
	int places;
	while (cin >> places && places) {
		map<int, Vertex> vertices;
		for (int i = 1; i <= places; i++) {
			vertices[i] = Vertex();
		}
		int src;
		while (cin >> src && src) {
			int dst;
			while (cin.peek() != '\n') {
				cin >> dst;
				vertices[src].neightbor.insert(dst);
				vertices[dst].neightbor.insert(src);
			}
		}
		int critical = 0;
		dfsTree(vertices, 1, 0, 1, critical);
		cout << critical << endl;
	}
	return 0;
}