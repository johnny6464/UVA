#include<iostream>
#include<vector>
using namespace std;

int root(vector<int>& v, int id) {
	return id == v[id] ? id : v[id] = root(v, v[id]);
}

int main() {
	int num;
	cin >> num;

	int cmd, n1, n2;
	vector<int> sets(num * 2);
	for (int i = 0; i < num * 2; i++) {
		sets[i] = i;
	}

	while (cin >> cmd >> n1 >> n2 && (cmd || n1 || n2)) {
		int f1 = root(sets, n1), e1 = root(sets, n1 + num);
		int f2 = root(sets, n2), e2 = root(sets, n2 + num);
		switch (cmd) {
		case 1:
			if (f1 == e2 || e1 == f2) {
				cout << "-1" << endl;
			}
			else {
				sets[f1] = f2;
				sets[e1] = e2;
			}
			break;
		case 2:
			if (f1 == f2 || e1 == e2) {
				cout << "-1" << endl;
			}
			else {
				sets[f1] = e2;
				sets[e1] = f2;
			}
			break;
		case 3:
			cout << (f1 == f2) << endl;
			break;
		case 4:
			cout << (f1 == e2) << endl;
			break;
		default:
			break;
		}
	}
	return 0;
}