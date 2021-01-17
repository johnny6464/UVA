#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

string permutation(string& s, long long n, vector<long long>& factorial) {
	string answer;
	vector<bool> use(s.size(), false);
	for (int i = s.size() - 1; i >= 0; i--) {
		int index = int(n / factorial[i]), count = 0;
		for (size_t i = 0; i < s.size(); i++) {
			if (!use[i]) {
				if (count == index) {
					answer += s[i];
					use[i] = true;
					break;
				}
				else {
					count++;
				}
			}
		}
		n %= factorial[i];
	}
	return answer;
}

int main() {
	vector<long long> factorial(21, 1);
	for (int i = 1; i < 21; i++) {
		factorial[i] = factorial[i - 1] * i;
	}

	int cases;
	cin >> cases;
	while (cases--) {
		string s;
		long long N;
		cin >> s >> N;

		N %= factorial[s.size()];
		sort(s.begin(), s.end());
		cout << permutation(s, N, factorial) << endl;
	}
	return 0;
}