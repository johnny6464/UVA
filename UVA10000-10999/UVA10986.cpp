#include<iostream>
#include<set>
#include<queue>
using namespace std;

struct Node {
	int id = 0;
	int distance = 1000000000;
	bool visited = false;
	set<pair<int, int>> neighbor;
	bool operator>(const Node& a) const {
		return this->distance > a.distance;
	}
};

int dijkstra(vector<Node>& maze, int src, int dst) {
	maze[src].distance = 0;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(maze[src]);

	for (int i = 1; i <= maze.size(); i++) {
		int target = -1; 
		while (!pq.empty()) {
			Node n = pq.top();
			pq.pop();
			if (!maze[n.id].visited) {
				target = n.id;
				break;
			}
		}
		if (target == -1) {
			break;
		}
		maze[target].visited = true;
		for (auto iter = maze[target].neighbor.begin(); iter != maze[target].neighbor.end(); iter++) {
			if (maze[target].distance + iter->second < maze[iter->first].distance) {
				maze[iter->first].distance = maze[target].distance + iter->second;
				if (!maze[iter->first].visited) {
					pq.push(maze[iter->first]);
				}
			}
		}
	}
	return maze[dst].distance;
}

int main() {
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		int n, m, S, T;
		cin >> n >> m >> S >> T;

		vector<Node> maze(n, Node());
		for (int i = 0; i < n; i++) {
			maze[i].id = i;
		}
		for (int i = 0; i < m; i++) {
			int src, dst, time;
			cin >> src >> dst >> time;
			maze[src].neighbor.insert(pair<int, int>(dst, time));
			maze[dst].neighbor.insert(pair<int, int>(src, time));
		}
		int d = dijkstra(maze, S, T);
		if (d == 1000000000) {
			cout << "Case #" << i << ": " << "unreachable" << endl;
		}
		else {
			cout << "Case #" << i << ": " << d << endl;
		}
	}
	return 0;
}