#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void draw(vector<vector<char>>& graph, char target, char color, size_t x, size_t y) {
	if (x < 0 || x >= graph.size() || y < 0 || y >= graph[0].size() || graph[x][y] != target) {
		return;
	}
	graph[x][y] = color;
	draw(graph, target, color, x - 1, y);
	draw(graph, target, color, x + 1, y);
	draw(graph, target, color, x, y - 1);
	draw(graph, target, color, x, y + 1);
}

int main() {
	char instruction;
	int M = 0, N = 0, X, Y, X1, X2, Y1, Y2;
	char C;
	string Name;
	vector<vector<char>> graph;
	while (cin >> instruction && instruction != 'X') {
		switch (instruction) {
		case 'I':
			cin >> M >> N;
			graph.clear();;
			for (int i = 0; i < M; i++) {
				graph.push_back(vector<char>(N, 'O'));
			}
			break;
		case 'C':
			graph.clear();
			for (int i = 0; i < M; i++) {
				graph.push_back(vector<char>(N, 'O'));
			}
			break;
		case 'L':
			cin >> X >> Y >> C;
			if (X <= M && X >= 1 && Y <= N && Y >= 1) {
				graph[X - 1][Y - 1] = C;
			}
			break;
		case 'V':
			cin >> X >> Y1 >> Y2 >> C;
			if (Y1 > Y2) {
				swap(Y1, Y2);
			}
			for (int i = Y1 - 1; i <= Y2 - 1; i++) {
				graph[X - 1][i] = C;
			}
			break;
		case 'H':
			cin >> X1 >> X2 >> Y >> C;
			if (X1 > X2) {
				swap(X1, X2);
			}
			for (int i = X1 - 1; i <= X2 - 1; i++) {
				graph[i][Y - 1] = C;
			}
			break;
		case 'K':
			cin >> X1 >> Y1 >> X2 >> Y2 >> C;
			if (X1 > X2) {
				swap(X1, X2);
			}
			if (Y1 > Y2) {
				swap(Y1, Y2);
			}
			for (int i = X1 - 1; i <= X2 - 1; i++) {
				for (int j = Y1 - 1; j <= Y2 - 1; j++) {
					graph[i][j] = C;
				}
			}
			break;
		case 'F':
			cin >> X >> Y >> C;
			if (graph[X - 1][Y - 1] != C) {
				draw(graph, graph[X - 1][Y - 1], C, X - 1, Y - 1);
			}
			break;
		case 'S':
			cin >> Name;
			cout << Name << endl;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					cout << graph[j][i];
				}
				cout << endl;
			}
			break;
		default:
			break;
		}
	}
	return 0;
}