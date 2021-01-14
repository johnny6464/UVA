#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool find(vector<int>& v, int target) {
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		if (*iter == target) {
			return true;
		}
	}
	return false;
}

int main() {
	map<int, int> count;
	vector<int> v;
	int num;
	while (cin >> num) {
		if (!find(v, num)) {
			v.push_back(num);
		}
		count[num]++;
	}

	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << *iter << " " << count[*iter] << endl;
	}
	return 0;
}