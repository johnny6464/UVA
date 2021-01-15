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
	while (cin >> numerator >> denominator && numerator && denominator) {
		vector<pair<int, int>> record;
		int pos;
		while (true) {
			numerator *= 10;
			pos = find(record, numerator);
			if (numerator != 0 && pos == -1) {
				record.push_back(pair<int, int>(numerator, numerator / denominator));
				numerator %= denominator;
			}
			else {
				cout << ".";
				for (size_t i = 0; i < record.size(); i++) {
					cout << record[i].second;
					if ((i + 2) % 50 == 0 && i != record.size() - 1) {
						cout << endl;
					}
				}
				break;
			}
		}
		cout << endl;
		if (numerator) {
			cout << "The last " << record.size() - pos << " digits repeat forever.";
		}
		else {
			cout << "This expansion terminates.";
		}
		cout << endl << endl;
	}
	return 0;
}