#include<iostream>
#include<set>
#include<vector>
using namespace std;

struct Node {
	int distance = 1000000000;
	set<pair<int, int>> neighbor;
};

bool bellmanFord(vector<Node>& maze) {
	maze[0].distance = 0;
	for (int i = 0; i < maze.size() - 1; i++) {
		for (auto iter = maze.begin(); iter != maze.end(); iter++) {
			for (auto iter1 = iter->neighbor.begin(); iter1 != iter->neighbor.end(); iter1++) {
				if (iter->distance + iter1->second < maze[iter1->first].distance) {
					maze[iter1->first].distance = iter->distance + iter1->second;
				}
			}
		}
	}

	bool negativeCycle = false;
	for (auto iter = maze.begin(); iter != maze.end(); iter++) {
		for (auto iter1 = iter->neighbor.begin(); iter1 != iter->neighbor.end(); iter1++) {
			if (iter->distance + iter1->second < maze[iter1->first].distance) {
				negativeCycle = true;
				break;
			}
		}
	}
	return negativeCycle;
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int vertice, edges;
		cin >> vertice >> edges;

		vector<Node> maze(vertice, Node());
		for (int i = 0; i < edges; i++) {
			int src, dst, year;
			cin >> src >> dst >> year;
			maze[src].neighbor.insert(pair<int, int>(dst, year));
		}
		if (bellmanFord(maze)) {
			cout << "possible" << endl;
		}
		else {
			cout << "not possible" << endl;
		}
	}
	return 0;
}