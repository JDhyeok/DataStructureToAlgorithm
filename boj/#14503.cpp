#include<iostream>
#include<algorithm>
#include<queue>
#include<math.h>
#include<vector>
#include<stack>
#include<unordered_map>

using namespace std;

#define MAX 51

int R, C;
int ans = 0;;
int room[MAX][MAX];
bool visited[MAX][MAX];

void rearDrive(int&, int&, int&);		// 뒤로 한 칸 후진
void frontDrive(int&, int&, int&);		// 앞으로 한 칸 전진
bool isRearDrive(int, int, int);			// 해당 뒤방향으로 운전 가능하지 보기
bool isFrontDrive(int, int, int);		// 해당 방향으로 운전 가능하지 보기
void clean();							// 방치우기
bool isAvailableLeft(int, int, int);	// 현재에서 왼쪽 가능한지 보고 돌기
int decideDir(int, int, int);			// 방향 전환할 때 어느 방향인지 정하기
void runRobot(int& , int&, int&);		// 전체 로직

void runRobot(int& r, int& c, int& d) {

	while (1) {

		if(!visited[r][c])
			clean();
		visited[r][c] = true;

		//cout << "clean "<< ans << " : " << r << " " << c << "\n";

		int origin = d;
		d = decideDir(r, c, d);
		
		if (origin == d) {
			// 모두 돌리고 같은 방향이면 갈 곳이 없을 때 

			if (isFrontDrive(r, c, d)) {
				// case 0 : 앞으로는 갈 수 있을 때
				frontDrive(r, c, d);
			}
			else if (isRearDrive(r, c, d)) {
				// case 1 : 후진할 수 있다.
				rearDrive(r, c, d);
			}
			else {
				// case 2 : 후진할 수 없다.
				return;
			}
		}
		else {
			// 갈 수 있는 방향이 있을 때
			frontDrive(r,c,d);
		}

	}

}

void clean() {
	ans++;
}

int decideDir(int r, int c, int d) {
	int cnt = 0;

	while (cnt < 4) {
		int tmp = (d - 1);
		if (tmp < 0)
			tmp = 3;
		if (isAvailableLeft(r, c, tmp)) {
			d = tmp;
			break;
		}
		d = tmp;
		cnt++;
	}

	return d;
}

bool isAvailableLeft(int i, int j, int d) {
	switch (d) {
	case 0:
		i -= 1;
		break;
	case 1:
		j += 1;
		break;
	case 2:
		i += 1;
		break;
	case 3:
		j -= 1;
		break;
	}

	if (i < 0 || j < 0 || i >= R || j >= C)
		return false;

	if (room[i][j] == 1 || visited[i][j])
		return false;

	return true;
}

void frontDrive(int& i, int& j, int& d) {
	switch (d) {
	case 0:
		i -= 1;
		break;
	case 1:
		j += 1;
		break;
	case 2:
		i += 1;
		break;
	case 3:
		j -= 1;
		break;
	}
}

void rearDrive(int& i, int& j, int& d) {
	switch (d) {
	case 0:
		i += 1;
		break;
	case 1:
		j -= 1;
		break;
	case 2:
		i -= 1;
		break;
	case 3:
		j += 1;
		break;
	}
}
bool isFrontDrive(int i, int j, int d) {
	switch (d) {
	case 0:
		i -= 1;
		break;
	case 1:
		j += 1;
		break;
	case 2:
		i += 1;
		break;
	case 3:
		j -= 1;
		break;
	}

	if (i < 0 || j < 0 || i >= R || j >= C)
		return false;

	if (room[i][j] == 1 || visited[i][j])
		return false;

	return true;
}
bool isRearDrive(int i, int j, int d) {
	switch (d) {
	case 0:
		i += 1;
		break;
	case 1:
		j -= 1;
		break;
	case 2:
		i -= 1;
		break;
	case 3:
		j += 1;
		break;
	}

	if (i < 0 || j < 0 || i >= R || j >= C)
		return false;

	if (room[i][j] == 1)
		return false;

	return true;
}

int main() {

	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int r, c, d;

	cin >> R >> C;
	cin >> r >> c >> d;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> room[i][j];
			visited[i][j] = false;
		}
	}

	runRobot(r, c, d);

	cout << ans;

	return 0;
}
