#include<iostream>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

struct Point {
	int x, y, id;
	Point() : x(0), y(0), id(0) {};
	Point(int x, int y, int id) : x(x), y(y), id(id) {};
};

struct Edge {
	Point from, to;
	double distance;
	Edge(Point from, Point to) : from(from), to(to) {
		this->distance = sqrt(pow((this->from.x - this->to.x), 2) + pow((this->from.y - this->to.y), 2));
	}
};

bool operator>(const Edge& e1, const Edge& e2) {
	return e1.distance > e2.distance;
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
	int cases, count = 0;
	cin >> cases;
	while (cases--) {
		int num, threshold, x, y;
		cin >> num >> threshold;

		vector<Point> points;
		for (int i = 0; i < num; i++) {
			cin >> x >> y;
			points.push_back(Point(x, y, i));
		}
		priority_queue<Edge, vector<Edge>, greater<Edge>> edges;
		for (size_t i = 0; i < points.size(); i++) {
			for (size_t j = i + 1; j < points.size(); j++) {
				edges.push(Edge(points[i], points[j]));
			}
		}

		int select = 0, states = 1;
		double road = 0, railroad = 0;
		vector<int> root(num, -1);
		while (select < num - 1) {
			Edge e = edges.top();
			edges.pop();

			if (root[e.from.id] == -1 && root[e.to.id] == -1 || findRoot(root, e.from.id) != findRoot(root, e.to.id)) {
				unionSet(root, e.from.id, e.to.id);
				if (e.distance <= threshold) {
					road += e.distance;
				}
				else {
					railroad += e.distance;
					states++;
				}
				select++;
			}
		}
		cout << "Case #" << ++count << ": " << states << " " << round(road) << " " << round(railroad) << endl;
	}
	return 0;
}