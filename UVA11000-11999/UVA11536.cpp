#include<iostream>
#include<climits>
#include<queue>
#include<set>
using namespace std;

int main() {
	int cases, N, M, K;
	int* sequence, * inQueue;
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		cin >> N >> M >> K;
		
		sequence = new int[N + 1]{ 0, 1, 2, 3 };
		for (int i = 4; i <= N; i++) {
			sequence[i] = (sequence[i - 1] + sequence[i - 2] + sequence[i - 3]) % M + 1;
		}

		int min = INT_MAX;
		set<int> s;
		queue<int> q;
		inQueue = new int[K + 1]{ 0 };
		for (int j = 1; j <= N; j++) {
			q.push(sequence[j]);
			if (sequence[j] <= K) {
				inQueue[sequence[j]]++;
				if (s.size() < K) {
					s.insert(sequence[j]);
				}

				if (s.size() == K) {
					while (q.front() > K || inQueue[q.front()] > 1) {
						if (q.front() <= K) {
							inQueue[q.front()]--;
						}
						q.pop();
					}
					if (q.size() < min) {
						min = q.size();
					}
				}
			}
		}

		cout << "Case " << i << ": ";
		if (min == INT_MAX) {
			cout << "sequence nai" << endl;
		}
		else {
			cout << min << endl;
		}
		delete[] sequence, inQueue;
	}
	return 0;
}