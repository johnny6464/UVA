#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int turtles;
		cin >> turtles;
		cin.ignore(256, '\n');
		
		vector<string> originOrder(turtles), desireOrder(turtles);
		for (int i = 0; i < turtles; i++) {
			getline(cin, originOrder[i]);
		}
		for (int i = 0; i < turtles; i++) {
			getline(cin, desireOrder[i]);
		}

		vector<string> jump;
		for (int i = turtles - 1, j = turtles - 1; i >= 0 && j >= 0; ) {
			if (originOrder[i] == desireOrder[j]) {
				i--;
				j--;
			}
			else {
				jump.push_back(originOrder[i--]);
			}
		}

		stack<string> answer;
		for (int i = 0; i < jump.size(); i++) {
			for (int j = 0; j < jump.size(); j++) {
				if (desireOrder[i] == jump[j]) {
					answer.push(jump[j]);
				}
			}
		}

		while (!answer.empty()) {
			cout << answer.top() << endl;
			answer.pop();
		}
		cout << endl;
	}
	return 0;
}