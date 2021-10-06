#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 51

bool visited[MAX][MAX];
int map[MAX][MAX], W, H;
int way[8][2] = { {1,0}, {0,-1}, {-1,0}, {0,1}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

void init() {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}

}

void bfs(int si, int sj) {
	queue<pair<int, int>> q;

	q.push({ si, sj });
	visited[si][sj] = true;

	while (!q.empty()) {
		int curi = q.front().first;
		int curj = q.front().second;
		q.pop();

		for (int w = 0; w < 8; w++) {
			int ni = curi + way[w][0];
			int nj = curj + way[w][1];

			if (ni < 0 || nj < 0 || ni >= H || nj >= W || visited[ni][nj] || map[ni][nj] == 0)
				continue;
			
			visited[ni][nj] = true;
			q.push({ ni, nj });
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);



	while (1) {
		
		init();

		cin >> W >> H;

		if (W == 0 && H == 0)
			break;

		

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		int ans = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {


				if (map[i][j] == 1 && visited[i][j] == false) {
					bfs(i, j);
					ans++;
				}
			}
		}

		cout << ans << "\n";
	}
	
	return 0;
}

