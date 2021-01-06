#include<iostream>
#include<cmath>
using namespace std;

int main() {
	long long parts;
	while (cin >> parts && parts > 0) {
		if (parts == 1) {
			cout << 0 << "%" << endl;
		}
		else {
			cout << parts * 25 << "%" << endl;
		}
	}
	return 0;
}