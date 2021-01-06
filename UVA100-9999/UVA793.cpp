#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct Computer {
	int root;
	int size;
};

int root(vector<Computer>& v, int id) {
	return id == v[id].root ? id : root(v, v[id].root);
}

void connect(vector<Computer>& v, int c1, int c2) {
	int root1 = root(v, c1);
	int root2 = root(v, c2);
	if (v[root1].size > v[root2].size) {
		v[root2].root = root1;
		v[root1].size += v[root2].size;
	}
	else {
		v[root1].root = root2;
		v[root2].size += v[root1].size;
	}
}

int main() {
	int cases, computers;
	cin >> cases;
	while (cases--) {
		cin >> computers;
		cin.ignore();

		vector<Computer> v(computers + 1);
		for (int i = 1; i <= computers; i++) {
			v[i].root = i;
			v[i].size = 1;
		}

		string line, cmd;
		int c1, c2, correct = 0, wrong = 0;
		stringstream ss;
		while (getline(cin, line) && line != "") {
			ss << line;
			ss >> cmd >> c1 >> c2;
			ss.clear();

			if (cmd == "c") {
				connect(v, c1, c2);
			}
			else {
				if (root(v, c1) == root(v, c2)) {
					correct++;
				}
				else {
					wrong++;
				}
			}
		}
		cout << correct << "," << wrong << endl;
		if (cases) {
			cout << endl;
		}
	}
	return 0;
}