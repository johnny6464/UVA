#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	while (cases--) {
		int people;
		cin >> people;

		double sum = 0;
		vector<int> grade(people, 0);
		for (int i = 0; i < people; i++) {
			cin >> grade[i];
			sum += grade[i];
		}

		int greaterThanAvg = 0;
		double avg = sum / people;
		for (int i = 0; i < people; i++) {
			if (grade[i] > avg) {
				greaterThanAvg++;
			}
		}
		cout << fixed << setprecision(3) << (double(greaterThanAvg) / double(people)) * 100 << "%" << endl;
	}

	return 0;
}