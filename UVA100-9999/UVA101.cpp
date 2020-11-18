#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;

void returning(vector<list<int>>& Block, map<int, int>& Position, int target) {
	for (auto iter = Block[Position[target]].begin(); iter != Block[Position[target]].end(); iter++) {
		if (*iter == target) {
			iter++;
			while (iter != Block[Position[target]].end()) {
				Block[*iter].push_back(*iter);
				Position[*iter] = *iter;
				iter = Block[Position[target]].erase(iter);
			}
			break;
		}
	}
}


int main() {
	int blocks;
	cin >> blocks;

	vector<list<int>> Block(blocks, list<int>());
	map<int, int> Position;
	for (int i = 0; i < blocks; i++) {
		Block[i].push_back(i);
		Position[i] = i;
	}

	string ins1, ins2;
	int target, dest;
	while (cin >> ins1 && ins1 != "quit") {
		cin >> target >> ins2 >> dest;
		if (target == dest || Position[target] == Position[dest]) {
			continue;
		}

		if (ins1 == "move") {
			if (ins2 == "onto") {
				returning(Block, Position, target);
				returning(Block, Position, dest);
			}
			else {
				returning(Block, Position, target);
			}
			Block[Position[dest]].push_back(target);
			Block[Position[target]].pop_back();
			Position[target] = Position[dest];
		}
		else {
			if (ins2 == "onto") {
				returning(Block, Position, dest);
			}
			auto& listInstance = Block[Position[target]];
			int pos = Position[target];
			for (auto iter = listInstance.begin(); iter != listInstance.end(); iter++) {
				if (*iter == target) {
					while (iter != listInstance.end()) {
						Position[*iter++] = Position[dest];
					}
					break;
				}
			}

			auto& listInstance1 = Block[pos];
			for (auto iter = listInstance1.begin(); iter != listInstance1.end(); iter++) {
				if (*iter == target) {
					Block[Position[dest]].splice(Block[Position[dest]].end(), listInstance1, iter, listInstance1.end());
					break;
				}
			}
		}
	}

	for (int i = 0; i < blocks; i++) {
		cout << i << ":";
		for (auto iter = Block[i].begin(); iter != Block[i].end(); iter++) {
			cout << " " << *iter;
		}
		cout << endl;
	}
	return 0;
}