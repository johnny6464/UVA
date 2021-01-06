#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

int main() {
	int num;
	string line;
	set<int> A, B;
	while (getline(cin, line)) {
		stringstream ss;
		A.clear();
		B.clear();
		
		ss << line;
		while (ss >> num) {
			A.insert(num);
		}
		getline(cin, line);
		ss.clear();
		ss << line;
		while (ss >> num) {
			B.insert(num);
		}

		int sizeA = A.size(), sizeB = B.size();
		vector<int> _union(A.size() + B.size());
		auto dst = set_union(A.begin(), A.end(), B.begin(), B.end(), _union.begin());
		
		if (dst - _union.begin() == A.size() + B.size()) {
			cout << "A and B are disjoint" << endl;
		}
		else {
			if (sizeA == sizeB ) {
				if (dst - _union.begin() == sizeA) {
					cout << "A equals B" << endl;
				}
				else {
					cout << "I'm confused!" << endl;
				}
			}
			else if (sizeA > sizeB) {
				if (dst - _union.begin() == sizeA) {
					cout << "B is a proper subset of A" << endl;
				}
				else {
					cout << "I'm confused!" << endl;
				}
			}
			else {
				if (dst - _union.begin() == sizeB) {
					cout << "A is a proper subset of B" << endl;
				}
				else {
					cout << "I'm confused!" << endl;
				}
			}
		}
	}
	return 0;
}