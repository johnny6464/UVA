#include<iostream>
#include<vector>
using namespace std;

int main() {
	int dimension;
	while (cin >> dimension) {
		int corners = 1 << dimension;
		vector<int> weight(corners), potency(corners, 0);
		for (int i = 0; i < corners; i++) {
			cin >> weight[i];
		}
		for (int i = 0; i < corners; i++) {
			for (int j = 0; j < dimension; j++) {
				potency[i] += weight[i ^ (1 << j)];
			}
		}

		int max = 0, sum;
		for (int i = 0; i < corners; i++) {
			for (int j = 0; j < dimension; j++) {
				sum = potency[i] + potency[i ^ (1 << j)];
				if (sum > max) {
					max = sum;
				}
			}
		}
		cout << max << endl;
	}
	return 0;
}