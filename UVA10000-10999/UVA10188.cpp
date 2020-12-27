#include<iostream>
#include<string>
using namespace std;

int main() {
	int cases = 0, linesOfInput, linesOfAnswer;
	while (cin >> linesOfInput && linesOfInput) {
		string input, answer, temp;
		cin.ignore();
		for (int i = 0; i < linesOfInput; i++) {
			getline(cin, temp);
			input += temp + "\n";
		}
		cin >> linesOfAnswer;
		cin.ignore();
		for (int i = 0; i < linesOfAnswer; i++) {
			getline(cin, temp);
			answer += temp + "\n";
		}

		bool PE = false, WA = false;
		for (size_t i = 0, j = 0; i < input.size() || j < answer.size();) {
			if (i == input.size()) {
				for (; j < answer.size(); j++) {
					if (answer[j] >= '0' && answer[j] <= '9') {
						WA = true;
						break;
					}
				}
				break;
			}
			else if (j == answer.size()) {
				for (; i < input.size(); i++) {
					if (input[i] >= '0' && input[i] <= '9') {
						WA = true;
						break;
					}
				}
				break;
			}

			if (input[i] == answer[j]) {
				i++;
				j++;
			}
			else if (!(input[i] >= '0' && input[i] <= '9')) {
				i++;
				PE = true;
			}
			else if (!(answer[j] >= '0' && answer[j] <= '9')) {
				j++;
				PE = true;
			}
			else {
				WA = true;
				break;
			}
		}

		if (WA) {
			cout << "Run #" << ++cases << ": " << "Wrong Answer" << endl;
		}
		else if (PE || linesOfInput != linesOfAnswer) {
			cout << "Run #" << ++cases << ": " << "Presentation Error" << endl;
		}
		else {
			cout << "Run #" << ++cases << ": " << "Accepted" << endl;
		}
	}
	return 0;
}