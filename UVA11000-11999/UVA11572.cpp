#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int num;
		cin >> num;

		set<int> package;
		vector<int> order;
		int max = 0;
		int backtrack = 0;
		while (num--) {
			int id;
			cin >> id;

			order.push_back(id);
			if (package.find(id) != package.end()) {
				max = max > package.size() ? max : package.size();
				for (int i = backtrack; i < order.size(); i++) {
					if (order[i] == id) {
						backtrack = i + 1;
						break;
					}
					package.erase(order[i]);
				}	
			}
			else {
				package.insert(id);
			}
		}
		max = max > package.size() ? max : package.size();
		cout << max << endl;
	}

	return 0;
}