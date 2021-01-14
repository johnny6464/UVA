#include<iostream>
#include<string>
#include<map>
using namespace std;

map<char, double> duration{
	{'W', 1.0},
	{'H', 1.0 / 2},
	{'Q', 1.0 / 4},
	{'E', 1.0 / 8},
	{'S', 1.0 / 16},
	{'T', 1.0 / 32},
	{'X', 1.0 / 64}
};


int main() {
	string composition;
	while (cin >> composition && composition != "*") {
		composition = composition.substr(1);

		int correct = 0;
		while (!composition.empty()) {
			string measure = composition.substr(0, composition.find('/'));
			double time = 0.0;
			for (size_t i = 0; i < measure.size(); i++) {
				time += duration[measure[i]];
			}
			if (time == 1) {
				correct++;
			}
			composition = composition.substr(composition.find('/') + 1);
		}
		cout << correct << endl;
	}
	return 0;
}