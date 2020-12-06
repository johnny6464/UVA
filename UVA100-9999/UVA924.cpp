#include<iostream>
#include<set>
#include<map>
#include<queue>
using namespace std;

struct Node {
	int distance = -1;
	set<int> friends;
};

int main() {
	int employee;
	cin >> employee;
	
	int friends, id;
	map<int, Node> relation;
	for (int i = 0; i < employee; i++) {
		relation[i] = Node();
		cin >> friends;
		for (int j = 0; j < friends; j++) {
			cin >> id;
			relation[i].friends.insert(id);
		}
	}

	int queries, origin;
	cin >> queries;
	while (queries--) {
		cin >> origin;
		if (relation[origin].friends.size() == 0) {
			cout << 0 << endl;
			continue;
		}
		
		map<int, int> daily;
		map<int, Node> temp(relation);
		queue<int> solver;

		temp[origin].distance = 0;
		solver.push(origin);
		while (!solver.empty()) {
			int current = solver.front();
			int distance = temp[current].distance;
			for (auto iter = temp[current].friends.begin(); iter != temp[current].friends.end(); iter++) {
				if (temp[*iter].distance == -1) {
					daily[distance + 1]++;
					temp[*iter].distance = distance + 1;
					solver.push(*iter);
				}
			}
			solver.pop();
		}

		int max = 0, day = 0;
		for (auto iter = daily.begin(); iter != daily.end(); iter++) {
			if (iter->second > max) {
				max = iter->second;
				day = iter->first;
			}
		}
		cout << max << " " << day << endl;
	}
	return 0;
}