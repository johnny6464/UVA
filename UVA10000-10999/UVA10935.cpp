#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		queue<int> deck;
		for (int i = 1; i <= n; i++) {
			deck.push(i);
		}
		cout << "Discarded cards:";
		if (deck.size() > 1) {
			cout << " ";
		}
		while (deck.size() > 1) {
			if (deck.size() != 2) {
				cout << deck.front() << ", ";
			}
			else {
				cout << deck.front();
			}
			deck.pop();
			deck.push(deck.front());
			deck.pop();
		}
		cout << endl << "Remaining card: " << deck.front() << endl;
	}
	return 0;
}