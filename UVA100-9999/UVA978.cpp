#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int battlefield, green, blue;
		cin >> battlefield >> green >> blue;
		
		multiset<int, greater<int>> greens, blues;
		while (green--) {
			int power;
			cin >> power;
			greens.insert(power);
		}

		while (blue--) {
			int power;
			cin >> power;
			blues.insert(power);
		}

		while (!greens.empty() && !blues.empty()) {
			int size = greens.size() < blues.size() ? greens.size() : blues.size();
			size = size < battlefield ? size : battlefield;
			vector<int> result;
			
			auto iter1 = greens.begin();
			auto iter2 = blues.begin();
			int battle = size;
			while (battle--) {
				result.push_back(*(iter1++) - *(iter2++));
			}

			while (size--) {
				greens.erase(greens.begin());
				blues.erase(blues.begin());
			}

			for (auto iter = result.begin(); iter != result.end(); iter++) {
				if (*iter > 0) {
					greens.insert(*iter);
				}
				else if (*iter < 0) {
					blues.insert(-*iter);
				}
			}
		}


		if (greens.empty() && blues.empty()) {
			cout << "green and blue died" << endl;
		}
		else if (greens.empty()) {
			cout << "blue wins" << endl;
			for (multiset<int>::iterator iter = blues.begin(); iter != blues.end(); iter++) {
				cout << *iter << endl;
			}
		}
		else {
			cout << "green wins" << endl;
			for (multiset<int>::iterator iter = greens.begin(); iter != greens.end(); iter++) {
				cout << *iter << endl;
			}
		}

		if (cases) {
			cout << endl;
		}
	}
	return 0;
}