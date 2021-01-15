#include<iostream>
#include<cmath>
#include<set>
using namespace std;

int main() {
	int cases, n;
	long long k;
	cin >> cases;
	while (cases--) {
		cin >> n >> k;
		set<long long> s;
		s.insert(k);

		long long max = k, capacity = (int)pow(10, n);
		while (true) {
			k = k * k;
			while (k >= capacity) {
				k /= 10;
			}
			if (s.find(k) == s.end()) {
				s.insert(k);
				if (k > max) {
					max = k;
				}
			}
			else {
				break;
			}
		}
		cout << max << endl;
	}
	return 0;
}