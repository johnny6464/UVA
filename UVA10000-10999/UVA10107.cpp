#include<iostream>
#include<vector>
using namespace std;

int main() {
	long long num;
	vector<long long> v;
	while (cin >> num) {
		if (v.empty() || num >= v[v.size() - 1]) {
			v.push_back(num);
		}
		else {
			for (auto iter = v.begin(); iter != v.end(); iter++) {
				if (num < *iter) {
					v.insert(iter, num);
					break;
				}
			}
		}
		if (v.size() % 2 == 0) {
			cout << (v[(v.size() - 1) / 2] + v[v.size() / 2]) / 2 << endl;
		}
		else {
			cout << v[v.size() / 2] << endl;
		}
	}
	return 0;
}