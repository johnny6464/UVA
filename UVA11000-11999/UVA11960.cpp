#include<iostream>
using namespace std;

#define MAXN 1000000

int main() {
	int cases;
	cin >> cases;

	int answer[MAXN + 1] = { 0 };
	int fact[MAXN + 1] = { 0 };
	for (long long i = 2; i <= MAXN; i++) {
		if (!fact[i]) {
			fact[i] = i;
		}
		for (long long j = i * i; j <= MAXN; j += i) {
			if (!fact[j]) {
				fact[j] = i;
			}
		}
	}

	for (int i = 1; i <= MAXN; i++) {
		answer[i] = 1;

		int temp = i, currentPrime = 0;
		while (temp > 1) {
			int count = 0, prime = fact[temp];
			while (temp % prime == 0) {
				count++;
				temp /= prime;
			}
			answer[i] *= count + 1;
		}
	}

	int max = 0, most = 0;
	for (int i = 1; i <= MAXN; i++) {
		if (answer[i] >= max) {
			max = answer[i];
			most = i;
		}
		answer[i] = most;
	}

	int N;
	while (cases--) {
		cin >> N;
		cout << answer[N] << endl;
	}
	return 0;
}