#include<iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int e, f, c;
		cin >> e >> f >> c;

		int total = 0;
		int remain = e + f;
		while (remain >= c) {
			total += remain / c;
			remain = remain / c + remain % c;
		}
		cout << total << endl;
	}
	return 0;
}