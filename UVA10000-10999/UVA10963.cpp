#include<iostream>
#include<vector>
using namespace std;

int main() {
	int cases, col, north, south;
	cin >> cases;
	while (cases--) {
		cin >> col;

		vector<int> v;
		for (int i = 0; i < col; i++) {
			cin >> north >> south;
			v.push_back(north - south);
		}

		bool close = true;
		for (int i = 1; i < col; i++) {
			if (v[i] != v[0]) {
				close = false;
				break;
			}
		}

		if (close) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}

		if (cases) {
			cout << endl;
		}
	}
	return 0;
}