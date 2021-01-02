#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	cin.ignore();
	while (cases--) {
		string ciphertext;
		getline(cin, ciphertext);

		int sqrtSize = sqrt(ciphertext.size());
		if (sqrtSize * sqrtSize != ciphertext.size()) {
			cout << "INVALID" << endl;
		}
		else {
			for (int i = 0; i < sqrtSize; i++) {
				for (int j = 0; j < sqrtSize; j++) {
					cout << ciphertext[i + j * sqrtSize];
				}
			}
			cout << endl;
		}
	}
	return 0;
}