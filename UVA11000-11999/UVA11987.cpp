#include<iostream>
#include<vector>
using namespace std;

struct Group {
	int parent;
	int sum;
	int num;
	Group() :parent(0), sum(0), num(0) {};
	Group(int p, int s, int n) :parent(p), sum(s), num(n) {};
};

int findRoot(vector<Group>& groups, int id) {
	return id == groups[id].parent ? id : groups[id].parent = findRoot(groups, groups[id].parent);
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int> group(n + 1);
		vector<Group> groups(n + 1);
		for (int i = 1; i <= n; i++) {
			group[i] = i;
			groups[i] = Group(i, i, 1);
		}

		int cmd, p, q;
		for (int i = 0; i < m; i++) {
			cin >> cmd;
			if (cmd == 1) {
				cin >> p >> q;
				int g1 = findRoot(groups, group[p]), g2 = findRoot(groups, group[q]);
				if (g1 != g2) {
					groups[g1].parent = g2;
					groups[g2].sum += groups[g1].sum;
					groups[g2].num += groups[g1].num;
					groups[g1].num = groups[g1].sum = 0;
				}
			}
			else if (cmd == 2) {
				cin >> p >> q;
				int g1 = findRoot(groups, group[p]), g2 = findRoot(groups, group[q]);
				if (g1 != g2) {
					group[p] = g2;
					groups[g1].num--;
					groups[g1].sum -= p;
					groups[g2].num++;
					groups[g2].sum += p;
				}
			}
			else {
				cin >> p;
				int g = findRoot(groups, group[p]);
				cout << groups[g].num << " " << groups[g].sum << endl;
			}
		}
	}
	return 0;
}