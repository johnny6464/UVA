#include<iostream>
#include<queue>
using namespace std;

struct Node {
	int id = 0;
	int cost = 0;
	int distance = 1000000000;
	bool visited = false;
	bool operator>(const Node& a) const {
		return this->distance > a.distance;
	}
};

int dijkstraVariation(vector<Node>& maze, int rows, int cols) {
	maze[1].distance = maze[1].cost;
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	pq.push(maze[1]);

	int total = rows * cols;
	for (int i = 1; i <= total; i++) {
		int target = 0; 
		while (!pq.empty()) {
			Node n = pq.top();
			pq.pop();
			if (!maze[n.id].visited) {
				target = n.id;
				break;
			}
		}
		maze[target].visited = true;
		if (target % cols != 0) {
			if (maze[target].distance + maze[target + 1].cost < maze[target + 1].distance) {
				maze[target + 1].distance = maze[target].distance + maze[target + 1].cost;
				if (!maze[target + 1].visited) {
					pq.push(maze[target + 1]);
				}
			}
		}
		if (target % cols != 1) {
			if (maze[target].distance + maze[target - 1].cost < maze[target - 1].distance) {
				maze[target - 1].distance = maze[target].distance + maze[target - 1].cost;
				if (!maze[target - 1].visited) {
					pq.push(maze[target - 1]);
				}
			}
		}
		if (target + cols <= rows * cols) {
			if (maze[target].distance + maze[target + cols].cost < maze[target + cols].distance) {
				maze[target + cols].distance = maze[target].distance + maze[target + cols].cost;
				if (!maze[target + cols].visited) {
					pq.push(maze[target + cols]);
				}
			}
		}
		if (target - cols >= 1) {
			if (maze[target].distance + maze[target - cols].cost < maze[target - cols].distance) {
				maze[target - cols].distance = maze[target].distance + maze[target - cols].cost;
				if (!maze[target - cols].visited) {
					pq.push(maze[target - cols]);
				}
			}
		}
	}
	return maze[total].distance;
}

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int rows, cols;
		cin >> rows >> cols;

		vector<Node> maze(rows * cols + 1, Node());
		for (int i = 1; i <= rows * cols; i++) {
			cin >> maze[i].cost;
			maze[i].id = i;
		}
		cout << dijkstraVariation(maze, rows, cols) << endl;
	}
	return 0;
}