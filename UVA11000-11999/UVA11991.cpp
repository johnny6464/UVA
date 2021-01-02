#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		int element;
		map<int, vector<int>> position;
		for (int i = 1; i <= n; i++) {
			cin >> element;
			position[element].push_back(i);
		}

		int k, v;
		for (int i = 0; i < m; i++) {
			cin >> k >> v;
			if (position[v].size() >= k) {
				cout << position[v][k - 1] << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
	}
	return 0;
}