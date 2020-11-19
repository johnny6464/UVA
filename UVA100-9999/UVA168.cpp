#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

struct Node {
	bool hasCandle = false;
	vector<char> neightbor;
};


void dfs(map<char, Node>& maze, char posMinotaur, char posTheseus, int interval, int& step, char& trap) {
	for (auto iter = maze[posMinotaur].neightbor.begin(); iter != maze[posMinotaur].neightbor.end(); iter++) {
		if (*iter != posTheseus && !maze[*iter].hasCandle) {
			if (++step % interval == 0) {
				maze[posMinotaur].hasCandle = true;
				cout << posMinotaur << " ";
			}
			dfs(maze, *iter, posMinotaur, interval, step, trap);
			return;
		}
	}
	trap = posMinotaur;
}

int main() {
	string input;
	char posTheseus, posMinotaur;
	int interval;
	while (cin >> input && input != "#") {
		map<char, Node> maze;
		cin >> posMinotaur >> posTheseus >> interval;
		while (!input.empty()) {
			string temp = input.substr(0, input.find(';'));
			if (temp[temp.size() - 1] == '.') {
				temp = input.substr(0, temp.size() - 1);
			}
			
			for (int i = 2; i < temp.size(); i++) {
				maze[temp[0]].neightbor.push_back(temp[i]);
			}
			try {
				input = input.substr(temp.size() + 1);
			}
			catch (...) {
				break;
			}
		}

		int step = 0;
		char trap;
		dfs(maze, posMinotaur, posTheseus, interval, step, trap);
		cout << "/" << trap << endl;
	}
	return 0;
}