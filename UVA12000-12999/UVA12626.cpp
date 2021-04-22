#include<iostream>
#include<map>
using namespace std;

map<char, int> need{
	{'A', 3},
	{'G', 1},
	{'I', 1},
	{'M', 1},
	{'R', 2},
	{'T', 1}
};

int main() {
	int cases;
	string word;
	cin >> cases;
	while (cases--) {
		cin >> word;

		map<char, int> m;
		for (int i = 0; i < word.size(); i++) {
			m[word[i]]++;
		}

		int max = 1000;
		for (auto iter = need.begin(); iter != need.end(); iter++) {
			m[iter->first] /= iter->second;
			max = max < m[iter->first] ? max : m[iter->first];
		}
		cout << max << endl;
	}
	return 0;
}