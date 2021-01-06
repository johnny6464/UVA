#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

struct Computer {
	int root;
	int size;
};

int root(vector<Computer>& v, int id) {
	return id == v[id].root ? id : root(v, v[id].root);
}

bool connect(vector<Computer>& v, int c1, int c2) {
	int root1 = root(v, c1);
	int root2 = root(v, c2);
	if (root1 == root2) {
		return false;
	}

	if (v[root1].size > v[root2].size) {
		v[root2].root = root1;
		v[root1].size += v[root2].size;
	}
	else {
		v[root1].root = root2;
		v[root2].size += v[root1].size;
	}
	return true;
}

int main() {
	int cases, computers;
	cin >> cases;
	while (cases--) {
		cin >> computers;
		cin.ignore();

		int group = computers;
		vector<Computer> v(computers + 1);
		for (int i = 1; i <= computers; i++) {
			v[i].root = i;
			v[i].size = 1;
		}

		string line;
		int c1, c2;
		while (getline(cin, line) && line[0] != '\0') {
			stringstream ss(line);
			while (ss >> c1 >> c2) {
				if (connect(v, c1, c2)) {
					group--;
				}
			}
		}
		cout << group << endl;
		if (cases) {
			cout << endl;
		}
	}
	return 0;
}