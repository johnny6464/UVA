#include<iostream>
#include<cstring>
using namespace std;

int group[10][10][10];
int current[10];
bool visit[10];

int dfs(int d) {
	if (d == 3 && group[current[0]][current[1]][current[2]] == -1) {
		return -1;
	}
	if (d == 6 && group[current[3]][current[4]][current[5]] == -1) {
		return -1;
	}
	if (d == 9) {
		int total = 0;
		for (int i = 0; i < 3; i++) {
			if (group[current[i * 3]][current[i * 3 + 1]][current[i * 3 + 2]] == -1) {
				return -1;
			}
			total += group[current[i * 3]][current[i * 3 + 1]][current[i * 3 + 2]];
		}
		return total;
	}

	int answer = -1, score = -1;
	for (int i = 1; i < 10; i++) {
		if (!visit[i]) {
			visit[i] = true;
			current[d] = i;
			score = dfs(d + 1);
			if (score > answer) {
				answer = score;
			}
			visit[i] = false;
		}
	}
	return answer;
}

int main() {
	int combinations, a, b, c, s, cases = 0;
	while (cin >> combinations && combinations) {
		memset(group, -1, sizeof(group));
		memset(visit, false, sizeof(visit));

		for (int i = 0; i < combinations; i++) {
			cin >> a >> b >> c >> s;
			group[a][b][c] = s;
		}
		cout << "Case " << ++cases << ": " << dfs(0) << endl;
	}
	return 0;
}