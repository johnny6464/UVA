#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int groups;
	string s;
	while (cin >> groups && groups) {
		cin >> s;
		int size = s.size() / groups;

		for (int i = 0; i < s.size(); i+=size) {
			reverse(s.begin() + i, s.begin() + i + size);
		}
		cout << s << endl;
	}
	return 0;
}