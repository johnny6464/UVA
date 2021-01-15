#include<iostream>
#include<map>
using namespace std;

int main() {
	int number;
	while (cin >> number && number) {
		int age;
		map<int, int> m;
		for (int i = 0; i < number; i++) {
			cin >> age;
			m[age]++;
		}

		cout << m.begin()->first;
		m.begin()->second--;
		for (auto iter = m.begin(); iter != m.end(); iter++) {
			for (int i = 0; i < iter->second; i++) {
				cout << " " << iter->first;
			}
		}
		cout << endl;
	}
	return 0;
}