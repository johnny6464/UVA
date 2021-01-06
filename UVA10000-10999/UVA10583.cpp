#include<iostream>
#include<vector>
using namespace std;

struct Node {
	int root;
	int size;
};

int root(vector<Node>& v, int id) {
	return id == v[id].root ? id : v[id].root = root(v, v[id].root);
}

bool connect(vector<Node>& v, int n1, int n2) {
	int r1 = root(v, n1), r2 = root(v, n2);
	if (r1 == r2) {
		return false;
	}

	if (v[r1].size > v[r2].size) {
		v[r2].root = r1;
		v[r1].size += v[r2].size;
	}
	else {
		v[r1].root = r2;
		v[r2].size += v[r1].size;
	}
	return true;
}

int main() {
	int n, m, cases = 0;
	while (cin >> n >> m && n && m) {
		vector<Node> v(n + 1);
		for (int i = 1; i <= n; i++) {
			v[i].root = i;
			v[i].size = 1;
		}
		int n1, n2, group = n;
		for (int i = 0; i < m; i++) {
			cin >> n1 >> n2;
			if (connect(v, n1, n2)) {
				group--;
			}
		}
		cout << "Case " << ++cases << ": " << group << endl;
	}
	return 0;
}