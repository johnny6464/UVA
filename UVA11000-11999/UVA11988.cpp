#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
	string input;
	while (cin >> input) {
		list<char> answer;
		list<char>::iterator iter = answer.begin();
		for (char c : input) {
			if (c == '[') {
				iter = answer.begin();
			}
			else if (c == ']') {
				iter = answer.end();
			}
			else {
				answer.insert(iter, c);
			}
		}

		for (list<char>::iterator iter = answer.begin(); iter != answer.end(); iter++) {
			cout << *iter;
		}
		cout << endl;
	}
	return 0;
}