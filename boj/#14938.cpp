#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define MAX 101

int N, M, R;
int items[MAX];
int mat[MAX][MAX];
vector<pair<int, int>> edges[MAX];

void floyd() {
	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				mat[s][e] = min(mat[s][e], mat[s][m] + mat[m][e]);
			}
		}
	}
}

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == j)
				mat[i][j] = 0;
			else
				mat[i][j] = 987654321;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> R;

	init();

	for (int i = 1; i <= N; i++) {
		cin >> items[i];
	}

	int a, b, c;

	for (int i = 0; i < R; i++) {
		cin >> a >> b >> c;
		mat[a][b] = c;
		mat[b][a] = c;
	}

	floyd();

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		int num_item = 0;
		for (int j = 1; j <= N; j++) {
			if (mat[i][j] <= M)
				num_item += items[j];
		}
		ans = max(ans, num_item);
	}

	cout << ans << "\n";


	return 0;
}
