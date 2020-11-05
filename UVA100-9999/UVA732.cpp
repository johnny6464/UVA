#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(vector<char> &Src, vector<char> &Dest, vector<char> &Order, stack<char> &Stack) {
	if (!Src.empty()) {
		Order.push_back('i');
		Stack.push(Src.back());
		Src.pop_back();

		dfs(Src, Dest, Order, Stack);

		Src.push_back(Stack.top());
		Stack.pop();
		Order.pop_back();
	}
	if (!Stack.empty() && Stack.top() == Dest[Stack.size() + Src.size() - 1]) {
		Order.push_back('o');
		char temp = Stack.top();
		Stack.pop();

		dfs(Src, Dest, Order, Stack);

		Stack.push(temp);
		Order.pop_back();
	}

	if (Src.empty() && Stack.empty()) {
		for (vector<char>::iterator iter = Order.begin(); iter != Order.end() - 1; iter++) {
			cout << *iter << " ";
		}
		cout << *(Order.end() - 1) << endl;
	}
}

int main() {
	string before, after;
	while (cin >> before >> after) {
		cout << "[" << endl;
		
		if (before.size() == after.size() && !before.empty()) {
			vector<char> Src(before.rbegin(), before.rend());
			vector<char> Dest(after.rbegin(), after.rend());
			vector<char> Order;
			stack<char> Stack;
			dfs(Src, Dest, Order, Stack);
		}
		cout << "]" << endl;
	}

	return 0;
}