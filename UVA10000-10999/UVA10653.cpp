#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Node {
	bool hasBomb = false;
	bool isVisited = false;
};

struct Point {
	int x;
	int y;
	int distance;
	Point(int x, int y, int distance) {
		this->x = x;
		this->y = y;
		this->distance = distance;
	}
};

int main() {
	int R, C, dangerRows;
	while (cin >> R >> C && R && C) {
		cin >> dangerRows;

		vector<vector<Node>> land(R, vector<Node>(C, Node()));
		int rowId, bombCount, loc;
		while (dangerRows--) {
			cin >> rowId >> bombCount;
			while (bombCount--) {
				cin >> loc;
				land[rowId][loc].hasBomb = true;
			}
		}
		int srcX, srcY, dstX, dstY;
		cin >> srcX >> srcY >> dstX >> dstY;

		int distance = 0;
		queue<Point> solver;
		solver.push(Point(srcX, srcY, 0));
		while (!solver.empty()) {
			int x = solver.front().x;
			int y = solver.front().y;
			int d = solver.front().distance;
			if (x < 0 || x >= R || y < 0 || y >= C || land[x][y].hasBomb || land[x][y].isVisited) {
				solver.pop();
				continue;
			}
			if (x == dstX && y == dstY) {
				distance = d;
				break;
			}

			land[x][y].isVisited = true;
			solver.push(Point(x + 1, y, d + 1));
			solver.push(Point(x - 1, y, d + 1));
			solver.push(Point(x, y + 1, d + 1));
			solver.push(Point(x, y - 1, d + 1));
			solver.pop();
		}
		cout << distance << endl;
	}
	return 0;
}