#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<long long> v(51, 0);
	v[1] = 2;
	v[2] = 3;
	for (int i = 3; i <= 50; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}

	int cases, n;
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		cin >> n;	
		cout << "Scenario #" << i << ":" << endl;
		cout << v[n] << endl << endl;
	}
	return 0;
}