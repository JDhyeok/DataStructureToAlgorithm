#include<iostream>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

#define MAX 101

struct Point {
	int h, i, j;
	int day;
	Point(int h, int i, int j, int day) :h(h), i(i), j(j), day(day) {}
};

int N, M, H, noneCnt = 0, ans = 0;
int board[MAX][MAX][MAX];
int way[6][3] = { {0,0,1},{0,1,0},{1,0,0},{-1,0,0},{0,0,-1},{0,-1,0} };
vector<Point> riped;

int bfs() {
	int ans = 0;

	queue<Point> q;

	for (int i = 0; i < riped.size(); i++) {
		q.push(Point(riped[i].h, riped[i].i, riped[i].j, 0));
	}


	while (!q.empty()) {
		Point cur = q.front();
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nh = cur.h + way[i][0];
			int ni = cur.i + way[i][1];
			int nj = cur.j + way[i][2];
			int nDay = cur.day + 1;

			if (nh >= H || ni >= M || nj >= N || nh < 0 || ni < 0 || nj < 0)
				continue;

			if (board[nh][ni][nj] == -1 || board[nh][ni][nj] == 1)
				continue;

			ans = nDay;
			board[nh][ni][nj] = 1;
			riped.push_back(Point(nh, ni, nj, nDay));
			q.push(Point(nh, ni, nj, nDay));
		}
	}
	if(N*M*H - noneCnt - riped.size() > 0)
		return -1;

	return ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> board[i][j][k];
				if (board[i][j][k] == 1)
					riped.push_back(Point(i, j, k, 0));
				if (board[i][j][k] == -1)
					noneCnt++;
			}
		}
	}

	cout << bfs() << "\n";

	return 0;
}