#include<iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int amplitude, frequency;
		cin >> amplitude >> frequency;
		for (int i = 0; i < frequency; i++) {
			for (int j = 1; j < amplitude; j++) {
				for (int k = 0; k < j; k++) {
					cout << j;
				}
				cout << endl;
			}
			for (int j = amplitude; j > 0; j--) {
				for (int k = 0; k < j; k++) {
					cout << j;
				}
				cout << endl;
			}
			if (i != frequency - 1) {
				cout << endl;
			}
		}
		if (cases) {
			cout << endl;
		}
	}
	return 0;
}