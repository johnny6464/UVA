#include<iostream>
#include<set>
#include<map>
using namespace std;

int main() {
	int froshes;
	while (cin >> froshes && froshes) {
		map<set<int>, int> popularity;
		for (int i = 0; i < froshes; i++) {
			set<int> s;
			int course;
			for (int i = 0; i < 5; i++) {
				cin >> course;
				s.insert(course);
			}
			popularity[s]++;
		}

		int max = 0;
		for (map<set<int>, int>::iterator iter = popularity.begin(); iter != popularity.end(); iter++) {
			if (iter->second > max) {
				max = iter->second;
			}
		}

		int sum = 0;
		for (map<set<int>, int>::iterator iter = popularity.begin(); iter != popularity.end(); iter++) {
			if (iter->second == max) {
				sum += iter->second;
			}
		}

		cout << sum << endl;
	}
	return 0;
}