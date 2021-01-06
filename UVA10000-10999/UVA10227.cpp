#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

int main() {
	int cases, P, T;
	string line;
	cin >> cases;
	while (cases--) {
		cin >> P >> T;
		cin.ignore();

		vector<set<int>> v(P + 1);
		int people, tree;
		while (getline(cin, line) && line != "") {
			v[stoi(line.substr(0, line.find(' ')))].insert(stoi(line.substr(line.find(' ') + 1)));
		}

		set<set<int>> opinions;
		for (int i = 1; i <= P; i++) {
			opinions.insert(v[i]);
		}
		cout << opinions.size() << endl;

		if (cases) {
			cout << endl;
		}
	}
	return 0;
}