#include<iostream>
#include<sstream>
#include<iomanip>
#include<vector>
#include<string>
using namespace std;

typedef long long LL;

int main() {
	string s1, s2, line;
	while (getline(cin, line) && line != "0") {
		stringstream ss(line);
		ss >> s1 >> s2;

		if (s1 == "0" || s2 == "0") {
			int width = s1.size() > s2.size() ? s1.size() : s2.size();
			string dash(width, '-');
			cout << setw(width) << right << s1 << endl;
			cout << setw(width) << right << s2 << endl;
			cout << dash << endl;
			cout << setw(width) << right << 0 << endl << endl;
			continue;
		}
		vector<int> n1, n2, product(20, 0);
		for (int i = s1.size() - 1; i >= 0; i--) {
			n1.push_back(s1[i] - '0');
		}
		for (int i = s2.size() - 1; i >= 0; i--) {
			n2.push_back(s2[i] - '0');
		}
		
		int nonZero = 0;
		vector<LL> temp;
		for (size_t i = 0; i < n2.size(); i++) {
			LL sum = 0;
			int base = 1;
			for (size_t j = 0; j < n1.size(); j++) {
				product[i + j] += n2[i] * n1[j];
				sum += (long long)n2[i] * n1[j] * base;
				base *= 10;
			}
			temp.push_back(sum);
			if (sum != 0) {
				nonZero++;
			}
		}

		for (size_t i = 0; i < product.size(); i++) {
			if (product[i] >= 10) {
				product[i + 1] += product[i] / 10;
				product[i] %= 10;
			}
		}

		int maxSize = 0;
		for (int i = product.size() - 1; i >= 0; i--) {
			if (product[i] != 0) {
				maxSize = i;
				break;
			}
		}

		int width = maxSize + 1;
		string dash1(s1.size() > s2.size() ? s1.size() : s2.size(), '-'), dash2(width, '-');
		cout << setw(width) << right << s1 << endl;
		cout << setw(width) << right << s2 << endl;
		cout << setw(width) << right << dash1 << endl;
		for (size_t i = 0; i < temp.size(); i++, width--) {
			if (temp[i] == 0) {
				continue;
			}
			if (nonZero == 1) {
				cout << setw((LL)maxSize + 1) << setfill('0') << left << temp[i] << setfill(' ') << endl;
				break;
			}
			else {
				cout << setw(width) << right << temp[i] << endl;
			}
		}

		if (nonZero != 1) {
			cout << dash2 << endl;
			for (int i = maxSize; i >= 0; i--) {
				cout << product[i];
			}
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}