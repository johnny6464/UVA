#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct Query {
	int instuction = 0;
	int period = 0;
	int times = 1;

	bool operator>(const Query &other) const {
		if (period * times == other.period * other.times) {
			return instuction > other.instuction;
		}
		return period * times > other.period * other.times;
	}
};

int main() {
	priority_queue<Query, vector<Query>, greater<Query>> queries;
	string query;
	int order = 0;
	while (cin >> query && query != "#") {
		Query q;
		cin >> q.instuction >> q.period;
		queries.push(q);
	}

	int count;
	cin >> count;

	while (count--) {
		Query q = queries.top();
		cout << q.instuction << endl;

		queries.pop();
		Query newQuery(q);
		newQuery.times++;
		queries.push(newQuery);
	}
	return 0;
}