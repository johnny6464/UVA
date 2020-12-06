#include<iostream>
#include<set>
#include<map>
#include<queue>
#include<string>
using namespace std;

struct Node {
	bool isVisited = false;
	set<string> neighbor;
};

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		map<string, Node> relation;
		string word;
		while (cin >> word && word != "*") {
			relation[word] = Node();
			for (auto iter = relation.begin(); iter != relation.end(); iter++) {
				if (iter->first.size() == word.size()) {
					int diff = 0;
					for (int i = 0; i < word.size(); i++) {
						if (iter->first[i] != word[i]) {
							diff++;
						}
					}
					if (diff == 1) {
						relation[iter->first].neighbor.insert(word);
						relation[word].neighbor.insert(iter->first);
					}
				}
			}
		}
		cin.ignore();
		
		string temp, src, dst;
		while (getline(cin, temp) && temp != "") {
			for (auto iter = relation.begin(); iter != relation.end(); iter++) {
				iter->second.isVisited = false;
			}
			src = temp.substr(0, temp.find(' '));
			dst = temp.substr(temp.find(' ') + 1);

			int distance = 0;
			if (src != dst) {
				queue<pair<string, int>> finder;
				finder.push(pair<string, int>(src, 0));
				while (!finder.empty()) {
					string current = finder.front().first;
					relation[current].isVisited = true;
					if (current == dst) {
						distance = finder.front().second;
						break;
					}
					for (auto iter = relation[current].neighbor.begin(); iter != relation[current].neighbor.end(); iter++) {
						if (!relation[*iter].isVisited) {
							finder.push(pair<string, int>(*iter, finder.front().second + 1));
						}
					}
					finder.pop();
				}
			}
			cout << src << " " << dst << " " << distance << endl;
		}
		if (cases) {
			cout << endl;
		}
	}
	return 0;
}