#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node {
	int root;
	int size;
};

int root(vector<Node>& v, int id) {
	return id == v[id].root ? id : v[id].root = root(v, v[id].root);
}

void connect(vector<Node>& v, int n1, int n2) {
	int r1 = root(v, n1), r2 = root(v, n2);
	if (r1 == r2) {
		return;
	}

	if (v[r1].size > v[r2].size) {
		v[r2].root = r1;
		v[r1].size += v[r2].size;
	}
	else {
		v[r1].root = r2;
		v[r2].size += v[r1].size;
	}
}

int main() {
	int C, R;
	while (cin >> C >> R && C) {
		vector<Node> v(C + 1);
		map<string, int> m;
		string s1, s2;
		for (int i = 1; i <= C; i++) {
			cin >> s1;
			m[s1] = i;
			v[i].root = i;
			v[i].size = 1;
		}

		for (int i = 0; i < R; i++) {
			cin >> s1 >> s2;
			connect(v, m[s1], m[s2]);
		}

		int max = 0;
		for (int i = 1; i <= C; i++) {
			if (v[i].size > max) {
				max = v[i].size;
			}
		}
		cout << max << endl;
	}
	return 0;
}