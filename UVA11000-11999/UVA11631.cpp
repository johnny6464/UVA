#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

struct Edge {
	int src, dst, weight;
	Edge(int src, int dst, int weight) : src(src), dst(dst), weight(weight) {};
};

bool operator>(const Edge& e1, const Edge& e2) {
	return e1.weight > e2.weight;
}

int findRoot(vector<int>& root, int p) {
	while (root[p] > -1) {
		p = root[p];
	}
	return p;
}

void unionSet(vector<int>& root, int p1, int p2) {
	int root1 = findRoot(root, p1);
	int root2 = findRoot(root, p2);
	if (root[root1] < root[root2]) {
		root[root1] += root[root2];
		root[root2] = root1;
	}
	else {
		root[root2] += root[root1];
		root[root1] = root2;
	}
}

int main() {
	int vNum, eNum;
	while (cin >> vNum >> eNum && vNum && eNum) {
		int src, dst, weight, total = 0;
		priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
		for (int i = 0; i < eNum; i++) {
			cin >> src >> dst >> weight;
			edges.push(Edge(src, dst, weight));
			total += weight;
		}

		int cost = 0, select = 0;
		vector<int> root(vNum, -1);
		while (select < vNum - 1) {
			Edge e = edges.top();
			edges.pop();

			if (root[e.src] == -1 && root[e.dst] == -1 || findRoot(root, e.src) != findRoot(root, e.dst)) {
				unionSet(root, e.src, e.dst);
				cost += e.weight;
				select++;
			}
		}
		cout << total - cost << endl;
	}
	return 0;
}