#include<iostream>
#include<vector>
using namespace std;

void dfs(int d, int n, vector<bool>& state) {
	if (d == n + 1) {
		return;
	}
	dfs(d + 1, n, state);
	cout << "Move " << d << " from B" << (1 + !state[d]) << " to B" << (1 + state[d]) << endl;
	state[d] = !state[d];
	dfs(d + 1, n, state);
}
 
int main() {
	int cases, n, b1;
	cin >> cases;
	while (cases--) {
		cin >> n >> b1;

		vector<bool> state(n + 1, 0);
		int id;
		for (int i = 0; i < b1; i++) {
			cin >> id;
			state[id] = 1;
		}
		dfs(1, n, state);
		cout << endl;
	}
	return 0;
}