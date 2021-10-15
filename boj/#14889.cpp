#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

int N, arr[21][21];
int ans = 987654321;
bool visited[21];

void dfs(int cnt, int cur) {
	
	if (cnt == N / 2) {
		int start = 0, link = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i] && visited[j])
					start += arr[i][j];
				else if (!visited[i] && !visited[j])
					link += arr[i][j];
			}
		}

		int tmp = abs(start - link);
		ans = min(ans, tmp);

		return;
	}


	for (int i = cur; i < N; i++) {
		visited[i] = true;
		dfs(cnt + 1, i + 1);
		visited[i] = false;
	}
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	fill_n(visited, 21, false);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(0, 0);

	cout << ans;

	return 0;
}
