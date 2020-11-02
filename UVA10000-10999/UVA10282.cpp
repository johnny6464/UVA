#include<iostream>
#include<map>
#include<string>
using namespace std;


int main() {
	map<string, string> dict;
	string s;
	while (getline(cin, s)) {
		if (s == "") {
			break;
		}
		dict[s.substr(s.find(' ') + 1)] = s.substr(0, s.find(' '));
	}

	while (getline(cin, s)) {
		if (dict.find(s) != dict.end()) {
			cout << dict[s] << endl;
		}
		else {
			cout << "eh" << endl;
		}
	}
	return 0;
}