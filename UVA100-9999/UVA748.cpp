#include<iostream>
#include<vector>
using namespace std;


int stov(vector<short>& v, string s) {
	int trailingZeros = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == '0') {
			trailingZeros++;
		}
		else {
			break;
		}
	}
	s = s.substr(0, s.size() - trailingZeros);

	int decimal = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] != '.') {
			v.push_back(s[i] - '0');
		}
		else {
			decimal = s.size() - i - 1;
		}
	}
	return decimal;
}

vector<short> multiply(vector<short>& v1, vector<short>& v2) {
	vector<short> product(v1.size() + v2.size());
	for (size_t i = 0; i < v1.size(); i++) {
		for (size_t j = 0; j < v2.size(); j++) {
			product[i + j] += v1[i] * v2[j];
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
	product.resize(maxSize + 1);
	return product;
}


int main() {
	int n;
	string R;
	while (cin >> R >> n) {
		vector<short> v;
		size_t decimal = stov(v, R) * n;

		vector<short> product(1, 1);
		for (int i = 0; i < n; i++) {
			product = multiply(product, v);
		}

		if (product.size() < decimal) {
			cout << ".";
			for (size_t i = 0; i < decimal - product.size(); i++) {
				cout << "0";
			}
			for (int i = product.size() - 1; i >= 0; i--) {
				cout << product[i];
			}
		}
		else {
			for (int i = product.size() - 1; i >= 0; i--) {
				if (i + 1 == decimal) {
					cout << ".";
				}
				cout << product[i];
			}
		}
		cout << endl;
	}
	return 0;
}