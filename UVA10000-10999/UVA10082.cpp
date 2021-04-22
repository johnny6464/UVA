#include<iostream>
#include<string>
using namespace std;

const char keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;\'ZXCVBNM,./";

int main() {
	string word;
	while (getline(cin, word)) {
		for (size_t i = 0; i < word.size(); i++) {
			if (word[i] == ' ') {
				cout << ' ';
			}

			for (int j = 1; keyboard[j]; j++) {
				if (keyboard[j] == word[i]) {
					cout << keyboard[j - 1];
					break;
				}
			}
		}
		cout << endl;
	}
	return 0;
}