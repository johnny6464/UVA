#include<iostream>
#include<map>
#include<vector>
using namespace std;


void itov(vector<short>& v, int i) {
	while (i > 0) {
		v.push_back(i % 10);
		i /= 10;
	}
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
	map<int, int> record;
	record[0] = 1;
	while (cin >> n) {
		if (record.count(n) != 0) {
			cout << record[n] << endl;
		}
		else {
			vector<short> product(1, 1);
			for (int i = 1; i <= n; i++) {
				vector<short> num;
				itov(num, i);
				product = multiply(product, num);

				int sum = 0;
				for (int i = 0; i < product.size(); i++) {
					sum += product[i];
				}
				record[i] = sum;
			}
			cout << record[n] << endl;
		}
	}
	return 0;
}