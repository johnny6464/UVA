#include<iostream>
#include<map>
#include<vector>
using namespace std;

void dfs(map<int, int>& mailFlow, map<int, int>& maxReceiver, vector<int>& order, int index) {
	if (maxReceiver[index] == -1) {
		for (int i = 0; i < order.size(); i++) {
			if (order[i] == index) {
				int cycleLength = order.size() - i;
				for (int j = i; j < order.size(); j++) {
					maxReceiver[order[j]] = cycleLength;
				}
				for (int j = i - 1; j >= 0; j--) {
					maxReceiver[order[j]] = ++cycleLength;
				}
				break;
			}
		}
		return;
	}
	if (maxReceiver[index] > 0) {
		int cycleLength = maxReceiver[index];
		for (int i = order.size() - 1; i >= 0; i--) {
			maxReceiver[order[i]] = ++cycleLength;
		}
		return;
	}
	order.push_back(index);
	maxReceiver[index] = -1;
	dfs(mailFlow, maxReceiver, order, mailFlow[index]);
}

int main() {
	int cases;
	cin >> cases;
	int count = 1;
	while (cases--) {
		map<int, int> mailFlow;

		int num;
		cin >> num;
		while (num--) {
			int src, dst;
			cin >> src >> dst;
			mailFlow[src] = dst;
		}

		map<int, int> maxReceiver;
		vector<int> order;
		int max = 0;
		int first = 0;
		for (int i = 1; i <= mailFlow.size(); i++) {
			if (maxReceiver[i] == -1) {
				continue;
			}
			dfs(mailFlow, maxReceiver, order, i);
			order.clear();
			if (maxReceiver[i] > max) {
				max = maxReceiver[i];
				first = i;
			}
		}
		cout << "Case " << count++ << ": " << first << endl;
	}
	return 0;
}