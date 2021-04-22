#include<iostream>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<cfloat>
using namespace std;

struct Event {
	double value;
	double time;
	bool f;
};

bool operator<(const Event& e1, const Event& e2) {
	return e1.time < e2.time;
}

int main() {
	int N;
	while (cin >> N) {
		vector<Event> events;
		double value, time, accTime = 0.0;
		for (int i = 0; i < N; i++) {
			cin >> value >> time;
			events.push_back(Event{ value, accTime * 10000, true });
			accTime += time;
		}
		cin >> N;
		accTime = 0.0;
		for (int i = 0; i < N; i++) {
			cin >> value >> time;
			events.push_back(Event{ value, accTime * 10000, false });
			accTime += time;
		}
		sort(events.begin(), events.end());

		double answer = DBL_MAX, f = DBL_MIN, g = DBL_MIN, upper;
		for (size_t i = 0; i < events.size(); i++) {
			if (events[i].f) {
				f = events[i].value;
			}
			else {
				g = events[i].value;
			}
			if (i != events.size() - 1 && events[i + 1].time - events[i].time < 0.001 ) {
				continue;
			}
			upper = f > g ? f : g;
			answer = upper < answer ? upper : answer;
		}
		cout << fixed << setprecision(3) << answer << endl;
	}
	return 0;
}