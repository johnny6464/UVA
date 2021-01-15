#include<iostream>
#include<string>
#include<map>
using namespace std;

map<char, char> code{
	{'1', 'I'},
	{'2', 'Z'},
	{'3', 'E'},
	{'4', 'A'},
	{'5', 'S'},
	{'6', 'G'},
	{'7', 'T'},
	{'8', 'B'},
	{'9', 'P'},
	{'0', 'O'}
};


int main() {
	int cases;
	cin >> cases;
	cin.ignore();
	while (cases--) {
		string line;
		while (getline(cin, line) && line != "") {
			for (size_t i = 0; i < line.size(); i++) {
				if (line[i] <= '9' && line[i] >= '0') {
					line[i] = code[line[i]];
				}
			}
			cout << line << endl;
		}

		if (cases) {
			cout << endl;
		}
	}
	return 0;
}