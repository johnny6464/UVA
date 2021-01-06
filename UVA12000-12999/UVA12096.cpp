#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
#include<set>
using namespace std;

map<set<int>, int> IDCache;
vector<set<int>> SetCache;

int setToId(set<int> s) {
	if (IDCache.count(s)) {
		return IDCache[s];
	}
	SetCache.push_back(s);
	return IDCache[s] = SetCache.size() - 1;
}

int main() {
	int cases;
	cin >> cases;
	
	int num;
	string cmd;
	while (cases--) {
		stack<int> s;
		cin >> num;
		while (num--) {
			cin >> cmd;
			if (cmd == "PUSH") {
				s.push(setToId(set<int>()));
			}
			else if (cmd == "DUP") {
				s.push(s.top());
			}
			else {
				set<int> s1 = SetCache[s.top()];
				s.pop();
				set<int> s2 = SetCache[s.top()];
				s.pop();
				set<int> s3;

				if (cmd == "UNION") {
					set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
					s.push(setToId(s3));
				}
				else if (cmd == "INTERSECT") {
					set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
					s.push(setToId(s3));
				}
				else {
					s2.insert(setToId(s1));
					s.push(setToId(s2));
				}
			}
			cout << SetCache[s.top()].size() << endl;
		}
		cout << "***" << endl;
	}
	return 0;
}