#include<iostream>
using namespace std;

int main() {
	int N;
	while (cin >> N && N) {		
		int x = 0, stones;
		for (int i = 0; i < N; i++) {
			cin >> stones;
			x ^= stones;
		}
		if (x) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
	}
	return 0;
}