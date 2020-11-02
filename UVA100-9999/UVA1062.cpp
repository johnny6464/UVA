#include<iostream>
#include<vector>
using namespace std;

int main() {
	string container;
	int cases = 1;
	while (cin >> container && container != "end") {
		int len = container.size();
		vector<int> LIS(len, 1);

		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (container[i] < container[j] && LIS[i] + 1 > LIS[j]) {
					LIS[j] = LIS[i] + 1;
				}
			}
		}
		
		int max = 0;
		for (int i : LIS) {
			if (max < i) {
				max = i;
			}
		}
		cout << "Case " << cases++ << ": " << max << endl;
	}

	return 0;
}