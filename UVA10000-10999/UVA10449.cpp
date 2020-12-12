#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define INF 100000000
#define pow(x) ((x)*(x)*(x))

struct Node {
	int distance = INF;
	int busyness = 0;
	bool negativeCycle = false;
	set<pair<int, int>> neighbor;
};

void dfsNC(vector<Node>& city, int now) {
	city[now].negativeCycle = true;
	for (auto iter = city[now].neighbor.begin(); iter != city[now].neighbor.end(); iter++) {
		if (!city[iter->first].negativeCycle) {
			dfsNC(city, iter->first);
		}
	}
}

void bellmanFord(vector<Node>& city) {
	city[1].distance = 0;
	for (size_t i = 0; i < city.size() - 1; i++) {
		for (auto iter = city.begin(); iter != city.end(); iter++) {
			if (iter->distance != INF) {
				for (auto iter1 = iter->neighbor.begin(); iter1 != iter->neighbor.end(); iter1++) {
					if (iter->distance + iter1->second < city[iter1->first].distance) {
						city[iter1->first].distance = iter->distance + iter1->second;
					}
				}
			}
		}
	}

	for (size_t i = 1; i < city.size(); i++) {
		if (!city[i].negativeCycle) {
			for (auto iter = city[i].neighbor.begin(); iter != city[i].neighbor.end(); iter++) {
				if (city[i].distance + iter->second < city[iter->first].distance) {
					dfsNC(city, iter->first);
				}
			}
		}
	}
}

int main() {
	int vertice, edges, queries, cases = 0;
	while (cin >> vertice) {
		vector<Node> city(vertice + 1, Node());
		for (int i = 1; i <= vertice; i++) {
			cin >> city[i].busyness;
		}
		cin >> edges;
		for (int i = 1; i <= edges; i++) {
			int src, dst;
			cin >> src >> dst;
			city[src].neighbor.insert(pair<int, int>(dst, pow(city[dst].busyness - city[src].busyness)));
		}
		if (vertice > 0) {
			bellmanFord(city);
		}

		cout << "Set #" << ++cases << endl;
		cin >> queries;
		while (queries--) {
			int dst;
			cin >> dst;
			if (city[dst].distance == INF || city[dst].negativeCycle || city[dst].distance < 3) {
				cout << "?" << endl;
			}
			else{
				cout << city[dst].distance << endl;
			}
		}
	}
	return 0;
}