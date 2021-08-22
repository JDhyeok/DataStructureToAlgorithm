#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<unordered_map>

using namespace std;

#define INF 999999999

int N, E, a, b, c;
int v1, v2;
int matrix[802][802];
bool flag1 = false, flag2 = false;


void floyd() {

	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				matrix[s][e] = min(matrix[s][e], matrix[s][m] + matrix[m][e]);
			}
		}
	}
	
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> E;

	for (int i = 0; i < 802; i++) {
		for (int j = 0; j < 802; j++) {
			matrix[i][j] = INF;
			if (i == j)
				matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < E; i++) {
		cin >> a >> b >> c;
		matrix[a][b] = c;
		matrix[b][a] = c;
	}
	
	cin >> v1 >> v2;


	floyd();

	if (matrix[1][v1] >= INF || matrix[1][v2] >= INF || matrix[v1][v2] >= INF || matrix[v2][N] >= INF || matrix[v1][N] >= INF) {
		// 중간 연결이 끊겼을 때
		cout << -1 << "\n";
		return 0;
	}

	int way1, way2;

	// 1 > v1 > v2 > N
	way1 = matrix[1][v1] + matrix[v1][v2] + matrix[v2][N];

	// 1 > v2 > v1 > N
	way2 = matrix[1][v2] + matrix[v2][v1] + matrix[v1][N];

	int ans = min(way1, way2);

	cout << ans << "\n";

	return 0;
}
