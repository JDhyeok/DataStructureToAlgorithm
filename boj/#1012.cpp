#include <iostream>
#include <vector>

using namespace std;

int WAY[4][2] = { {1, 0}, {-1, 0}, {0,1}, {0,-1} };
int T, M, N, K;


void dfs(int farm[50][50], int i, int j) {

	farm[i][j] = 0;

	for (int w = 0; w < 4; w++) {
		int ni = i + WAY[w][0];
		int nj = j + WAY[w][1];

		if (ni < 0 || nj < 0 || ni >= N || nj >= M)
			continue;

		if (farm[ni][nj] == 1) {
			dfs(farm, ni, nj);
		}
	}
}

int main() {
	int ans = 0;
	
	int farm[50][50];

	cin >> T;
	
	while (T--) {
		ans = 0;
		cin >> M >> N >> K;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				farm[i][j] = 0;
			}
		}

		int x, y;
		for (int k = 0; k < K; k++) {
			cin >> x >> y;
			farm[y][x] = 1;
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (farm[i][j] == 1){
					dfs(farm, i , j);
					ans++;
				}
			}

		}


		cout << ans << endl;
	}

	
	return 0;

}
