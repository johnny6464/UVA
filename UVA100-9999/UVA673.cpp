#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	cin.ignore();
	while (cases--) {
		string sequence;
		getline(cin, sequence);

		stack<char> s;
		bool correct = true;
		for (int i = 0; i < sequence.size(); i++) {
			if (sequence[i] == '(' || sequence[i] == '[') {
				s.push(sequence[i]);
			}
			else if (sequence[i] == ')' || sequence[i] == ']') {
				if (s.empty()) {
					correct = false;
					break;
				}

				if (sequence[i] == ')' && s.top() == '(') {
					s.pop();
				}
				else if (sequence[i] == ']' && s.top() == '[') {
					s.pop();
				}
				else {
					correct = false;
					break;
				}
			}
		}
		if (correct && s.empty()) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}