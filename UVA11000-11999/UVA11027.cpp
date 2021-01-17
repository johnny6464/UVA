#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

typedef long long LL;

LL combinations(vector<LL>& factorial, map<char, int>& counter, int size) {
	LL total = factorial[size];
	for (auto iter = counter.begin(); iter != counter.end(); iter++) {
		if (iter->second) {
			total /= factorial[iter->second];
		}
	}
	return total;
}

string permutation(vector<LL>& factorial, map<char, int>& counter, size_t size, int target) {
	int round = size;
	string s;
	while (s.size() < round) {
		for (auto iter = counter.begin(); iter != counter.end(); iter++) {
			if (iter->second) {
				counter[iter->first]--;
				LL c = combinations(factorial, counter, size - 1);

				if (c > target) {
					s.push_back(iter->first);
					size--;
					break;
				}
				else {
					counter[iter->first]++;
					target -= c;
				}
			}
		}
	}
	return s;
}

int main() {
	vector<LL> factorial(16, 1);
	for (int i = 2; i < 16; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		string s;
		int n;
		cin >> s >> n;

		map<char, int> counter;
		for (size_t i = 0; i < s.size(); i++) {
			counter[s[i]]++;
		}

		int odd = 0;
		char mid;
		for (auto iter = counter.begin(); iter != counter.end() && odd <= 1; iter++) {
			if (iter->second % 2) {
				mid = iter->first;
				odd++;
			}
			iter->second /= 2;
		}

		cout << "Case " << i << ": ";
		if (odd > 1 || n > combinations(factorial, counter, s.size() / 2)) {
			cout << "XXX" << endl;
		}
		else {
			string answer = permutation(factorial, counter, s.size() / 2, n - 1);
			cout << answer;
			if (odd == 1) {
				cout << mid;
			}
			reverse(answer.begin(), answer.end());
			cout << answer << endl;
		}
	}
	return 0;
}