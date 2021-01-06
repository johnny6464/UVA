#include<iostream>
#include<vector>
using namespace std;

int main() {
	int cases, N, K;
	cin >> cases;
	while (cases--) {
		cin >> N >> K;
		vector<bool> coins(N + 1, true);
		vector<int> weight(N + 1, 1);
		for (int i = 0; i < K; i++) {
			int placed;
			char result;
			cin >> placed;
			vector<int> leftSide(placed, 0), rightSide(placed, 0);
			for (int i = 0; i < placed; i++) {
				cin >> leftSide[i];
			}
			for (int i = 0; i < placed; i++) {
				cin >> rightSide[i];
			}
			cin >> result;
			if (result == '=') {
				for (int i = 0; i < placed; i++) {
					coins[leftSide[i]] = 0;
					coins[rightSide[i]] = 0;
				}
			}
			else {
				vector<bool> temp(N + 1, false);
				for (int i = 0; i < placed; i++) {
					temp[leftSide[i]] = true;
					temp[rightSide[i]] = true;
				}
				for (int i = 1; i <= N; i++) {
					coins[i] = coins[i] & temp[i];
				}

				if (result == '>') {
					for (int i = 0; i < placed; i++) {
						if (weight[leftSide[i]] == 0) {
							coins[leftSide[i]] = 0;
						}
						weight[leftSide[i]] = 2;

						if (weight[rightSide[i]] == 2) {
							coins[rightSide[i]] = 0;
						}
						weight[rightSide[i]] = 0;
					}
				}
				else {
					for (int i = 0; i < placed; i++) {
						if (weight[leftSide[i]] == 2) {
							coins[leftSide[i]] = 0;
						}
						weight[leftSide[i]] = 0;

						if (weight[rightSide[i]] == 0) {
							coins[rightSide[i]] = 0;
						}
						weight[rightSide[i]] = 2;
					}
				}
			}
		}

		int count = 0, fake = 0;
		for (int i = 1; i <= N; i++) {
			if (coins[i]) {
				count++;
				fake = i;
			}
		}
		if (count == 1) {
			cout << fake << endl;
		}
		else {
			cout << 0 << endl;
		}

		if (cases) {
			cout << endl;
		}
	}
	return 0;
}