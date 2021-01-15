#include<iostream>
#include<vector>
using namespace std;

int find(vector<pair<int, int>>& v, int target) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i].first == target) {
			return i;
		}
	}
	return -1;
}

int main() {
	int numerator, denominator;
	while (cin >> numerator >> denominator) {
		cout << numerator << "/" << denominator << " = " << numerator / denominator << ".";

		numerator %= denominator;
		vector<pair<int, int>> record;
		int pos;
		while (true) {
			numerator *= 10;
			pos = find(record, numerator);
			if (pos == -1) {
				record.push_back(pair<int, int>(numerator, numerator / denominator));
				numerator %= denominator;
			}
			else {
				for (int i = 0; i < pos; i++) {
					cout << record[i].second;
				}

				cout << "(";
				for (size_t i = pos; i < record.size() && i < pos + 50; i++) {
					cout << record[i].second;
				}
				if (record.size() - pos > 50) {
					cout << "...";
				}
				cout << ")";
				break;
			}
		}
		cout << endl;
		cout << "   " << record.size() - pos << " = number of digits in repeating cycle" << endl << endl;
	}
	return 0;
}