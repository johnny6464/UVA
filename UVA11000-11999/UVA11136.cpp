#include<iostream>
#include<set>
using namespace std;

int main() {
	int days;
	while (cin >> days && days) {
		multiset<int> urn;
		long long paid = 0;
		while (days--) {
			int count;
			cin >> count;
			while (count--) {
				int price;
				cin >> price;
				urn.insert(price);
			}
			int max = *(urn.rbegin());
			int min = *(urn.begin());
			urn.erase(urn.find(max));
			urn.erase(urn.find(min));
			paid += max - min;
		}
		cout << paid << endl;
	}
	return 0;
}