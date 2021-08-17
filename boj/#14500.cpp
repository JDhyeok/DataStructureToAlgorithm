#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;


int N, M, ans = 0;
short map[500][500];

int linear[8][4] = { {0 ,0}, { 0, 1},{0,2},{0,3},
					{0,0},{1,0},{2,0},{3,0} };

int square[4][4] = { {0,0},{0,1},{1,0},{1,1} };

int mountain[16][4] = { {0,0},{0,1},{0,-1},{1,0},
					{0,0},{-1,0},{1,0},{0,1},
					{0,0},{-1,0},{0,-1},{0,1},
					{0,0},{-1,0},{1,0},{0,-1} };

int light[16][4] = { {0,0},{-1,0},{0,1},{1,1},
					{0,0}, {0,1}, {1,0}, {1,-1},
					{0,0},{0,1},{-1,1},{1,0},
					{0,0},{0,-1},{1,0},{1,1} };

int question1[16][4] = { {0,0},{0,1},{-1,0},{-2,0},
					{0,0}, {0,1}, {0,2}, {1,0},
					{0,0},{1,0},{2,0},{0,-1},
					{0,0},{-1,0},{0,-1},{0,-2} };

int question2[16][4] = { {0,0},{0,-1},{-1,0},{-2,0},
					{0,0}, {0,1}, {0,2}, {-1,0},
					{0,0},{1,0},{2,0},{0,1},
					{0,0},{1,0},{0,-1},{0,-2} };



void solver(int i, int j);

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
		cin >> N >> M;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				solver(i, j);
			}
		}


		cout << ans << "\n";
	
	return 0;
}

bool RangeCheck(int a, int b) {
	if (a < 0 || b < 0 || a >= N || b >= M)
		return true;
	return false;
}

void solver(int curi, int curj) {
	int sum = 0;

	// linear
	for (int i = 0; i < 8; i+=4) {
		sum = 0;
		int ni1 = curi + linear[i][0];
		int nj1 = curj + linear[i][1];
		if (RangeCheck(ni1, nj1))
			continue;

		int ni2 = curi + linear[i+1][0];
		int nj2 = curj + linear[i+1][1];
		if (RangeCheck(ni2, nj2))
			continue;

		int ni3 = curi + linear[i+2][0];
		int nj3 = curj + linear[i+2][1];
		if (RangeCheck(ni3, nj3))
			continue;

		int ni4 = curi + linear[i+3][0];
		int nj4 = curj + linear[i+3][1];
		if (RangeCheck(ni4, nj4))
			continue;

		sum += map[ni1][nj1] + map[ni2][nj2] + map[ni3][nj3] + map[ni4][nj4];
		ans = max(ans, sum);
	}

	sum = 0;
	// square
	for (int i = 0; i < 4; i += 4) {
		sum = 0;
		int ni1 = curi + square[i][0];
		int nj1 = curj + square[i][1];
		if (RangeCheck(ni1, nj1))
			continue;

		int ni2 = curi + square[i + 1][0];
		int nj2 = curj + square[i + 1][1];
		if (RangeCheck(ni2, nj2))
			continue;

		int ni3 = curi + square[i + 2][0];
		int nj3 = curj + square[i + 2][1];
		if (RangeCheck(ni3, nj3))
			continue;

		int ni4 = curi + square[i + 3][0];
		int nj4 = curj + square[i + 3][1];
		if (RangeCheck(ni4, nj4))
			continue;

		sum += map[ni1][nj1] + map[ni2][nj2] + map[ni3][nj3] + map[ni4][nj4];
		ans = max(ans, sum);
	}

	sum = 0;
	// mountain
	for (int i = 0; i < 16; i += 4) {
		sum = 0;
		int ni1 = curi + mountain[i][0];
		int nj1 = curj + mountain[i][1];
		if (RangeCheck(ni1, nj1))
			continue;

		int ni2 = curi + mountain[i + 1][0];
		int nj2 = curj + mountain[i + 1][1];
		if (RangeCheck(ni2, nj2))
			continue;

		int ni3 = curi + mountain[i + 2][0];
		int nj3 = curj + mountain[i + 2][1];
		if (RangeCheck(ni3, nj3))
			continue;

		int ni4 = curi + mountain[i + 3][0];
		int nj4 = curj + mountain[i + 3][1];
		if (RangeCheck(ni4, nj4))
			continue;

		sum += map[ni1][nj1] + map[ni2][nj2] + map[ni3][nj3] + map[ni4][nj4];
		ans = max(ans, sum);
	}

	sum = 0;
	// light
	for (int i = 0; i < 16; i += 4) {
		sum = 0;
		int ni1 = curi + light[i][0];
		int nj1 = curj + light[i][1];
		if (RangeCheck(ni1, nj1))
			continue;

		int ni2 = curi + light[i + 1][0];
		int nj2 = curj + light[i + 1][1];
		if (RangeCheck(ni2, nj2))
			continue;

		int ni3 = curi + light[i + 2][0];
		int nj3 = curj + light[i + 2][1];
		if (RangeCheck(ni3, nj3))
			continue;

		int ni4 = curi + light[i + 3][0];
		int nj4 = curj + light[i + 3][1];
		if (RangeCheck(ni4, nj4))
			continue;

		sum += map[ni1][nj1] + map[ni2][nj2] + map[ni3][nj3] + map[ni4][nj4];
		ans = max(ans, sum);
	}

	sum = 0;
	// question1
	for (int i = 0; i < 16; i += 4) {
		sum = 0;
		int ni1 = curi + question1[i][0];
		int nj1 = curj + question1[i][1];
		if (RangeCheck(ni1, nj1))
			continue;

		int ni2 = curi + question1[i + 1][0];
		int nj2 = curj + question1[i + 1][1];
		if (RangeCheck(ni2, nj2))
			continue;

		int ni3 = curi + question1[i + 2][0];
		int nj3 = curj + question1[i + 2][1];
		if (RangeCheck(ni3, nj3))
			continue;

		int ni4 = curi + question1[i + 3][0];
		int nj4 = curj + question1[i + 3][1];
		if (RangeCheck(ni4, nj4))
			continue;

		sum += map[ni1][nj1] + map[ni2][nj2] + map[ni3][nj3] + map[ni4][nj4];
		ans = max(ans, sum);
	}

	sum = 0;
	// question2
	for (int i = 0; i < 16; i += 4) {
		sum = 0;
		int ni1 = curi + question2[i][0];
		int nj1 = curj + question2[i][1];
		if (RangeCheck(ni1, nj1))
			continue;

		int ni2 = curi + question2[i + 1][0];
		int nj2 = curj + question2[i + 1][1];
		if (RangeCheck(ni2, nj2))
			continue;

		int ni3 = curi + question2[i + 2][0];
		int nj3 = curj + question2[i + 2][1];
		if (RangeCheck(ni3, nj3))
			continue;
		
		int ni4 = curi + question2[i + 3][0];
		int nj4 = curj + question2[i + 3][1];
		if (RangeCheck(ni4, nj4))
			continue;

		sum += map[ni1][nj1] + map[ni2][nj2] + map[ni3][nj3] + map[ni4][nj4];
		ans = max(ans, sum);
	}
}