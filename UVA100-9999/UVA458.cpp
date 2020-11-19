#include<iostream>
#include<string>
using namespace std;


int main() {
	string cipher;
	while (getline(cin, cipher)) {
		for (int i = 0; i < cipher.size(); i++) {
			cout << char(cipher[i] - 7);
		}
		cout << endl;
	}
	return 0;
}