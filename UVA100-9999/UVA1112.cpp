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

int dijkstra(vector<Node>& maze, int goal, int time) {
	maze[goal].distance = 0;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(maze[goal]);

	for (int i = 1; i <= maze.size(); i++) {
		int target = 0; 
		while (!pq.empty()) {
			Node n = pq.top();
			pq.pop();
			if (!maze[n.id].visited) {
				target = n.id;
				break;
			}
		}
		if (!target) {
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

	int escape = 0;
	for (auto iter = maze.begin(); iter != maze.end(); iter++) {
		if (iter->distance <= time) {
			escape++;
		}
	}
	return escape;
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int N, E, T, M;
		cin >> N >> E >> T >> M;

		vector<Node> maze(N + 1, Node());
		for (int i = 1; i <= N; i++) {
			maze[i].id = i;
		}
		for (int i = 1; i <= M; i++) {
			int src, dst, time;
			cin >> src >> dst >> time;
			maze[dst].neighbor.insert(pair<int, int>(src, time));
		}
		cout << dijkstra(maze, E, T) << endl;
		if (cases) {
			cout << endl;
		}
	}
	return 0;
}