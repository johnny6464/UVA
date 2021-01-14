#include<iostream>
#include<vector>
using namespace std;

int backtrack(int n, int col, int ld, int rd, vector<int>& board) {
	if (n == board.size()) {
		return 1;
	}

	int solutions = 0;
	int pos = ((1 << board.size())) - 1 & ~(board[n] | col | ld | rd);
	while (pos) {
		int p = pos & -pos;
		pos -= p;
		solutions += backtrack(n + 1, col + p, (ld + p) << 1, (rd + p) >> 1, board);
	}
	return solutions;
}

int main() {
	int size, cases = 0;
	while (cin >> size && size) {	
		char c;
		vector<int> board(size, 0);
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> c;
				if (c == '*') {
					board[i] += 1 << j;
				}
			}
		}
		cout << "Case " << ++cases << ": " << backtrack(0, 0, 0, 0, board) << endl;
	}
	return 0;
}