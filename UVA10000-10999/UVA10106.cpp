#include<iostream>
#include<vector>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		vector<int> n1(251, 0), n2(251, 0), product(502, 0);
		for (int i = 0, j = s1.size() - 1; j >= 0; i++, j--) {
			n1[i] = s1[j] - '0';
		}
		for (int i = 0, j = s2.size() - 1; j >= 0; i++, j--) {
			n2[i] = s2[j] - '0';
		}
		
		for (size_t i = 0; i < n1.size(); i++) {
			for (size_t j = 0; j < n2.size(); j++) {
				product[i + j] += n1[i] * n2[j];
			}
		}

		for (size_t i = 0; i < product.size(); i++) {
			if (product[i] >= 10) {
				product[i + 1] += product[i] / 10;
				product[i] %= 10;
			}
		}

		bool print = false;
		for (int i = product.size() - 1; i >= 0; i--) {
			if (product[i] != 0) {
				print = true;
			}
			if (print) {
				cout << product[i];
			}
		}
		if (!print) {
			cout << 0;
		}
		cout << endl;
	}
	return 0;
}