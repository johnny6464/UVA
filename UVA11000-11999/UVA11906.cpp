#include<iostream>
#include<vector>
using namespace std;

int R, C, M, N;

bool dfs(vector<vector<int>>& land, int x, int y, int& even, int& odd) {
	if (x < 0 || x >= R || y < 0 || y >= C || land[x][y] == -1) {
		return false;
	}
	if (land[x][y] == 1) {
		return true;
	}
	
	land[x][y] = 1;
	int step = 0;

	for (int i = -1; i < 2; i += 2) {
		for (int j = -1; j < 2; j += 2) {
			if (dfs(land, x + (i * M), y + (j * N), even, odd)) step++;
			if (M != N) {
				if (dfs(land, x + (i * N), y + (j * M), even, odd)) step++;
			}
		}
	}
	if (M == 0 || N == 0) {
		step /= 2;
	}

	if (step & 1) {
		odd++;
	}
	else {
		even++;
	}
	return true;
}

int main() {
	int cases;
	cin >> cases;

	int count = 1;
	while (cases--) {
		int W;
		int even = 0, odd = 0;

		cin >> R >> C >> M >> N >> W;
		vector<vector<int>> land(R, vector<int>(C, 0));
		while (W--) {
			int x, y;
			cin >> x >> y;
			land[x][y] = -1;
		}
		dfs(land, 0, 0, even, odd);
		cout << "Case " << count++ << ": " << even << " " << odd << endl;
	}
	return 0;
}