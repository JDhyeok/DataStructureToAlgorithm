#include<iostream>

using namespace std;

#define MAX 1001
#define INF 10001

int N, M;
int visited[MAX];
int adjMat[MAX][MAX];

void dfs(int s, int e, int w) {
	visited[s] = w;

	for (int i = 1; i <= N; i++) {
		if (adjMat[s][i] > 0 && visited[i] == INF) {
			dfs(i, e, w + adjMat[s][i]);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int a, b, c;
	for (int i = 1; i < N; i++) {
		cin >> a >> b >> c;
		adjMat[a][b] = c;
		adjMat[b][a] = c;
	}

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		fill_n(visited, MAX, INF);

		dfs(a, b, 0);

		cout << visited[b] << "\n";
	}

	return 0;
}