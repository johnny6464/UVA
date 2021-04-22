#include<iostream>
#include<map>
using namespace std;

map<char, int> soundex{
	{'B', 1},
	{'F', 1},
	{'P', 1},
	{'V', 1},
	{'C', 2},
	{'G', 2},
	{'J', 2},
	{'K', 2},
	{'Q', 2},
	{'S', 2},
	{'X', 2},
	{'Z', 2},
	{'D', 3},
	{'T', 3},
	{'L', 4},
	{'M', 5},
	{'N', 5},
	{'R', 6}
};

int main() {
	string word;
	while (cin >> word) {
		for (int i = 0; i < word.size(); i++) {
			if (soundex.count(word[i]) != 0) {
				if (i == 0 || soundex.count(word[i - 1]) == 0 || soundex[word[i]] != soundex[word[i - 1]]) {
					cout << soundex[word[i]];
				}
			}
		}
		cout << endl;
	}
	return 0;
}