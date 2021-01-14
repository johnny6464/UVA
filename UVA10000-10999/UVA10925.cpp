#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printVector(vector<int>& v) {
	bool print = false;
	for (int i = v.size() - 1; i >= 1; i--) {
		if (v[i] != 0) {
			print = true;
		}
		if (print) {
			cout << v[i];
		}
	}

	if (!print) {
		cout << 0;
	}
}

int main() {
	int items, friends, cases = 0;
	while (cin >> items >> friends && (items || friends)) {
		vector<int> total(25, 0);
		string item;
		for (int i = 0; i < items; i++) {
			cin >> item;
			reverse(item.begin(), item.end());
			for (size_t j = 0; j < item.size(); j++) {
				total[j + 1] += item[j] - '0';
			}
		}

		for (size_t i = 1; i < total.size(); i++) {
			if (total[i] >= 10) {
				total[i + 1] += total[i] / 10;
				total[i] %= 10;
			}
		}

		cout << "Bill #" << ++cases << " costs ";
		printVector(total);

		for (int i = total.size() - 1; i >= 1; i--) {
			total[i - 1] += (total[i] % friends) * 10;
			total[i] /= friends;
		}
		cout << ": each friend should pay ";
		printVector(total);
		cout << endl << endl;
	}
	return 0;
}