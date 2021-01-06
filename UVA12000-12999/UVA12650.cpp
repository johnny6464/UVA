#include<iostream>
#include<vector>
using namespace std;

int main() {
	int N, R;
	while (cin >> N >> R) {
		int card;
		vector<bool> id(N + 1, false);
		for (int i = 0; i < R; i++) {
			cin >> card;
			id[card] = true;
		}
		if (N == R) {
			cout << "*" << endl;
			continue;
		}
		for (int i = 1; i <= N; i++) {
			if (!id[i]) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
	return 0;
}