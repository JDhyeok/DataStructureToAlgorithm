#include<iostream>

using namespace std;

#define MAX 21

int R, C, ans = 0;
int way[4][2] = { {0,1},{1,0},{-1,0},{0,-1} };
char map[MAX][MAX];

void dfs(int curi, int curj, int mask, int depth) {
	
	mask |= (1 << (map[curi][curj] - 'A'));

	for (int w = 0; w < 4; w++) {
		int ni = curi + way[w][0];
		int nj = curj + way[w][1];

		if (ni < 0 || nj < 0 || ni >= R || nj >= C)
			continue;
		if (mask & (1 << (map[ni][nj] - 'A')))
			continue;

		dfs(ni, nj, mask, depth + 1);
	}

	ans = max(ans, depth);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	
	dfs(0, 0, 0, 0);

	cout << ans + 1;

	return 0;
}