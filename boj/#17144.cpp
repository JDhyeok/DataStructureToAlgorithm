#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

#define MAX 50

// Global Variances
struct Point {
	int i, j;
	Point(int i, int j) :i(i), j(j) {}
};

int R, C, T;
int way[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int room[MAX][MAX], diffusedDust[MAX][MAX];
//queue<Point> dust;
vector<Point> dust;
vector<Point> refresher;

// Functions
void diffusion();
void runRefresher();
void clockwiseRotate(Point);
void counterClockwiseRotate(Point);
void addDust();
int calcDiffusableDust(int);


int calcDiffusableDust(int dust) {
	// 확산될 미세먼지 양 계산
	return (dust / 5);
}

void diffusion() {

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			diffusedDust[i][j] = 0;

	int N = dust.size();

	// 현재 있는 dust의 확산을 diffusedDust에 쌓아둠
	for (int i = 0; i < N; i++) {
		int curi = dust[i].i;
		int curj = dust[i].j;

		int curDust = room[curi][curj];
		int available = 0;

		// 확산될 미세먼지 양
		int nextDust = calcDiffusableDust(curDust);

		if (nextDust == 0)
			continue;

		// 4방향 탐색
		for (int w = 0; w < 4; w++) {
			int ni = curi + way[w][0];
			int nj = curj + way[w][1];

			if (ni < 0 || nj < 0 || ni >= R || nj >= C || room[ni][nj] == -1)
				continue;

			// 확산된 미세먼지 개수
			available++;
			dust.push_back(Point(ni, nj));
			diffusedDust[ni][nj] += nextDust;
		}

		// 현재 dust에서 확산된 만큼 감소해주고 dust가 남아있기 때문에 계속 push
		room[curi][curj] -= (nextDust * available);
	}

	addDust();

}

void addDust() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] == -1)
				continue;
			room[i][j] += diffusedDust[i][j];
		}
	}
}

void runRefresher() {
	counterClockwiseRotate(refresher[0]);
	clockwiseRotate(refresher[1]);
}

void clockwiseRotate(Point down) {
	int si = down.i;
	int sj = down.j;

	int pre = 0, tmp;
	// 오른쪽으로 밀기
	for (int j = sj + 1; j < C; j++) {
		tmp = room[si][j];
		room[si][j] = pre;
		pre = tmp;
	}

	// 아래쪽으로 밀기
	for (int i = si + 1; i < R; i++) {
		tmp = room[i][C - 1];
		room[i][C - 1] = pre;
		pre = tmp;
	}

	if (R - 1 == si)
		return;

	// 왼쪽으로 밀기
	for (int j = C - 2; j >= 0; j--) {
		tmp = room[R - 1][j];
		room[R - 1][j] = pre;
		pre = tmp;
	}

	// 위쪽으로 밀기
	for (int i = R - 2; i > si; i--) {
		tmp = room[i][sj];
		room[i][sj] = pre;
		pre = tmp;
	}
}

void counterClockwiseRotate(Point up) {
	int si = up.i;
	int sj = up.j;

	int pre = 0, tmp;
	// 오른쪽으로 밀기
	for (int j = sj + 1; j < C; j++) {
		tmp = room[si][j];
		room[si][j] = pre;
		pre = tmp;
	}

	// 위쪽으로 밀기
	for (int i = si - 1; i >= 0; i--) {
		tmp = room[i][C - 1];
		room[i][C - 1] = pre;
		pre = tmp;
	}

	if (si == 0)
		return;

	// 왼쪽으로 밀기
	for (int j = C - 2; j >= 0; j--) {
		tmp = room[0][j];
		room[0][j] = pre;
		pre = tmp;
	}

	// 아래쪽으로 밀기
	for (int i = 1; i < si; i++) {
		tmp = room[i][0];
		room[i][0] = pre;
		pre = tmp;
	}
}

int countDust() {
	int ans = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] == -1)
				continue;
			ans += room[i][j];
		}
	}

	return ans;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C >> T;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			if (room[i][j] > 0)
				dust.push_back(Point(i, j));
			if (room[i][j] == -1) {
				refresher.push_back(Point(i, j));
			}
		}
	}

	while (T--) {
		diffusion();
		runRefresher();

		dust.clear();
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (room[i][j] > 0)
					dust.push_back(Point(i, j));
			}
		}
	}

	int ans = countDust();
	
	cout << ans << "\n";


	return 0;
}