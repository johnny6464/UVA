#include<iostream>
#include<vector>
using namespace std;

int main() {
	string sentence;
	while (cin >> sentence) {
		bool legal = true;
		vector<char> v;
		for (int i = 0; i < sentence.size(); i++) {
			if (sentence[i] > 'Z') {
				v.push_back('a');
			}
			else if (sentence[i] == 'N') {
				v.push_back('b');
			}
			else {
				v.push_back('c');
			}

			while (v.size() > 1) {
				if (v.size() > 2 && v.back() == 'a' && v[v.size() - 2] == 'a' && v[v.size() - 3] == 'c') {
					v.pop_back();
					v.pop_back();
					v.pop_back();
					v.push_back('a');
				}
				else if (v.back() == 'a' && v[v.size() - 2] == 'b') {
					v.pop_back();
					v.pop_back();
					v.push_back('a');
				}
				else {
					break;
				}
			}
		}

		if (v.size() == 1&& v[0] == 'a') {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}