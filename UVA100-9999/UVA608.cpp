#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		bitset<12> coins("111111111111");
		vector<int> weight(12, 1);
		string leftSide, rightSide, result;
		for (size_t i = 0; i < 3; i++) {
			cin >> leftSide >> rightSide >> result;
			if (result == "even") {
				for (size_t i = 0; i < leftSide.size(); i++) {
					coins[leftSide[i] - 'A'] = 0;
					coins[rightSide[i] - 'A'] = 0;
				}
			}
			else {
				bitset<12> temp("000000000000");
				for (size_t i = 0; i < leftSide.size(); i++) {
					temp[leftSide[i] - 'A'] = 1;
					temp[rightSide[i] - 'A'] = 1;
				}
				coins &= temp;

				if (result == "up") {
					for (size_t i = 0; i < leftSide.size(); i++) {
						if (weight[leftSide[i] - 'A'] == 0) {
							coins[leftSide[i] - 'A'] = 0;
						}
						weight[leftSide[i] - 'A'] = 2;

						if (weight[rightSide[i] - 'A'] == 2) {
							coins[rightSide[i] - 'A'] = 0;
						}
						weight[rightSide[i] - 'A'] = 0;
					}
				}
				else {
					for (size_t i = 0; i < leftSide.size(); i++) {
						if (weight[leftSide[i] - 'A'] == 2) {
							coins[leftSide[i] - 'A'] = 0;
						}
						weight[leftSide[i] - 'A'] = 0;

						if (weight[rightSide[i] - 'A'] == 0) {
							coins[rightSide[i] - 'A'] = 0;
						}
						weight[rightSide[i] - 'A'] = 2;
					}
				}
			}
		}
		for (size_t i = 0; i < coins.size(); i++) {
			if (coins[i]) {
				cout << char(i + 'A') << " is the counterfeit coin and it is ";
				if (weight[i] == 2) {
					cout << "heavy." << endl;
				}
				else {
					cout << "light." << endl;
				}
				break;
			}
		}
	}
	return 0;
}