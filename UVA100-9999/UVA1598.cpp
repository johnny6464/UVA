#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct Transaction {
	int id, size, price;
	bool buy;
	Transaction() : id(0), size(0), price(0), buy(true) {};
	Transaction(int id, int size, int price, bool buy) :id(id), size(size), price(price), buy(buy) {};
};

void checkEmpty(priority_queue<int, vector<int>, less<int>>& buyPrice, priority_queue<int, vector<int>, greater<int>>& sellPrice
	, map<int, vector<Transaction>>& demand, map<int, vector<Transaction>>& supply) {
	while (!buyPrice.empty()) {
		if (demand.find(buyPrice.top()) == demand.end()) {
			buyPrice.pop();
		}
		else if (demand[buyPrice.top()].empty()) {
			demand.erase(buyPrice.top());
			buyPrice.pop();
		}
		else {
			break;
		}
	}
	while (!sellPrice.empty()) {
		if (supply.find(sellPrice.top()) == supply.end()) {
			sellPrice.pop();
		}
		else if (supply[sellPrice.top()].empty()) {
			supply.erase(sellPrice.top());
			sellPrice.pop();
		}
		else {
			break;
		}
	}
}


int main() {
	int count, cases = 0;
	while (cin >> count) {
		if (cases++) {
			cout << endl;
		}
		vector<Transaction> transactions(count + 1);
		priority_queue<int, vector<int>, less<int>> buyPrice;
		priority_queue<int, vector<int>, greater<int>> sellPrice;
		map<int, vector<Transaction>> demand, supply;
		int size, price, id;
		string cmd;
		for (int i = 1; i <= count; i++) {
			cin >> cmd;
			if (cmd == "BUY") {
				cin >> size >> price;
				if (demand.find(price) == demand.end()) {
					buyPrice.push(price);
				}
				demand[price].push_back(Transaction(i, size, price, true));
				transactions[i] = Transaction(i, size, price, true);
			}
			else if (cmd == "SELL") {
				cin >> size >> price;
				if (supply.find(price) == supply.end()) {
					sellPrice.push(price);
				}
				supply[price].push_back(Transaction(i, size, price, false));
				transactions[i] = Transaction(i, size, price, false);
			}
			else {
				cin >> id;
				if (transactions[id].buy) {
					for (auto iter = demand[transactions[id].price].begin(); iter != demand[transactions[id].price].end(); iter++) {
						if (iter->id == id) {
							demand[transactions[id].price].erase(iter);
							break;
						}
					}
					if (demand[transactions[id].price].empty()) {
						demand.erase(transactions[id].price);
						if (!buyPrice.empty() && transactions[id].price == buyPrice.top()) {
							buyPrice.pop();
						}
					}
				}
				else {
					for (auto iter = supply[transactions[id].price].begin(); iter != supply[transactions[id].price].end(); iter++) {
						if (iter->id == id) {
							supply[transactions[id].price].erase(iter);
							break;
						}
					}
					if (supply[transactions[id].price].empty()) {
						supply.erase(transactions[id].price);
						if (!sellPrice.empty() && transactions[id].price == sellPrice.top()) {
							sellPrice.pop();
						}
					}
				}
			}

			checkEmpty(buyPrice, sellPrice, demand, supply);
			while (!buyPrice.empty() && !sellPrice.empty()) {
				if (buyPrice.top() >= sellPrice.top()) {
					vector<Transaction>& txBuy = demand[buyPrice.top()];
					vector<Transaction>& txSell = supply[sellPrice.top()];

					int deal = (cmd == "BUY") ? sellPrice.top() : buyPrice.top();
					while (!txBuy.empty() && !txSell.empty()) {
						if (txBuy[0].size >= txSell[0].size) {
							cout << "TRADE " << txSell[0].size << " " << deal << endl;
							txBuy[0].size -= txSell[0].size;
							txSell.erase(txSell.begin());
							if (txBuy[0].size == 0) {
								txBuy.erase(txBuy.begin());
							}
						}
						else {
							cout << "TRADE " << txBuy[0].size << " " << deal << endl;
							txSell[0].size -= txBuy[0].size;
							txBuy.erase(txBuy.begin());
						}
					}

					if (txBuy.empty()) {
						demand.erase(buyPrice.top());
						buyPrice.pop();
					}
					if (txSell.empty()) {
						supply.erase(sellPrice.top());
						sellPrice.pop();
					}
				}
				else {
					break;
				}
			}
			checkEmpty(buyPrice, sellPrice, demand, supply);
			cout << "QUOTE ";
			if (buyPrice.empty()) {
				cout << "0 0 - ";
			}
			else {
				int sum = 0;
				for (auto iter = demand[buyPrice.top()].begin(); iter != demand[buyPrice.top()].end(); iter++) {
					sum += iter->size;
				}
				cout << sum << " " << buyPrice.top() << " - ";
			}
			if (sellPrice.empty()) {
				cout << "0 99999" << endl;
			}
			else {
				int sum = 0;
				for (auto iter = supply[sellPrice.top()].begin(); iter != supply[sellPrice.top()].end(); iter++) {
					sum += iter->size;
				}
				cout << sum << " " << sellPrice.top() << endl;
			}
		}
	}
	return 0;
}