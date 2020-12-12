#include<iostream>
#include<set>
#include<vector>
using namespace std;

#define INF 100000000

struct Node {
	int distance = INF;
	int energy = 0;
	bool negativeCycle = false;
	set<int> neighbor;
};

void dfs(vector<Node>& rooms, int now) {
	rooms[now].negativeCycle = true;
	for (auto iter = rooms[now].neighbor.begin(); iter != rooms[now].neighbor.end(); iter++) {
		if (!rooms[*iter].negativeCycle) {
			dfs(rooms, *iter);
		}
	}
}

bool bellmanFord(vector<Node>& rooms) {
	rooms[1].distance = 0;
	for (size_t i = 0; i < rooms.size() - 1; i++) {
		for (auto iter = rooms.begin(); iter != rooms.end(); iter++) {
			if (iter->distance != INF && iter->distance < 100) {
				for (auto iter1 = iter->neighbor.begin(); iter1 != iter->neighbor.end(); iter1++) {
					if (iter->distance + rooms[*iter1].energy < rooms[*iter1].distance) {
						rooms[*iter1].distance = iter->distance + rooms[*iter1].energy;
					}
				}
			}
		}
	}

	for (auto iter = rooms.begin(); iter != rooms.end() && !rooms[rooms.size() - 1].negativeCycle; iter++) {
		if (iter->distance != INF && iter->distance < 100) {
			for (auto iter1 = iter->neighbor.begin(); iter1 != iter->neighbor.end(); iter1++) {
				if (iter->distance + rooms[*iter1].energy < rooms[*iter1].distance) {
					dfs(rooms, *iter1);
				}
			}
		}
	}

	return rooms[rooms.size() - 1].negativeCycle || rooms[rooms.size() - 1].distance < 100;
}

int main() {
	int vertice;
	while (cin >> vertice && vertice != -1) {
		vector<Node> rooms(vertice + 1, Node());
		for (int i = 1; i <= vertice; i++) {
			int energy, neighbors, id;
			cin >> energy >> neighbors;
			rooms[i].energy = -energy;
			while (neighbors--) {
				cin >> id;
				rooms[i].neighbor.insert(id);
			}
		}
		if (bellmanFord(rooms)) {
			cout << "winnable" << endl;
		}
		else {
			cout << "hopeless" << endl;
		}
	}
	return 0;
}