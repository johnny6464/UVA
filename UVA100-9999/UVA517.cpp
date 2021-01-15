#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

string minExp(string s) {
	string smallest(s);
	for (size_t i = 0; i < s.size() - 1; i++) {
		rotate(s.begin(), s.begin() + 1, s.end());
		if (s < smallest) {
			smallest = s;
		}
	}
	return smallest;
}

int main() {
	int length, s;
	string init;
	while (cin >> length) {
		cin >> init;

		map<string, char> rules;
		string rule;
		for (int i = 0; i < 8; i++) {
			cin >> rule;
			rules[rule.substr(0, 3)] = rule[3];
		}

		bool print = false;
		map<string, int> order;
		cin >> s;
		for (int i = 0; i < s; i++) {
			init = minExp(init);
			if (order.find(init) == order.end()) {
				order[init] = order.size();
				string transform(init);
				for (int j = 0; j < length; j++) {
					string temp;
					temp.push_back(init[(j - 2 + length) % length]);
					temp.push_back(init[j]);
					temp.push_back(init[(j + 1) % length]);
					transform[j] = rules[temp];
				}
				init = transform;
			}
			else {
				s -= i;
				s %= order.size() - order[init];
				for (auto iter = order.begin(); iter != order.end(); iter++) {
					if (iter->second - order[init] == s) {
						cout << iter->first << endl;
						print = true;
						break;
					}
				}
				break;
			}
		}

		if (!print) {
			cout << init << endl;
		}
	}
	return 0;
}