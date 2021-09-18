#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define WHITE 0
#define BLUE 1
#define MAX 129

struct Point {
	int i, j;
	Point(int x, int y) : i(x), j(y) {}
};

int N, blueCount = 0, whiteCount = 0;
int paper[MAX][MAX];

bool isOnePaper(Point start, Point end, int color) {
	for (int i = start.i; i < end.i; i++) {
		for (int j = start.j; j < end.j; j++) {
			if (paper[i][j] != color)
				return false;
		}
	}
	return true;
}

void countPaper(Point start, Point end) {
	if (start.i > end.i || start.j > end.j)
		return;

	if (start.i == end.i && start.j == end.j) {
		if (paper[start.i][start.j] == 0)
			whiteCount++;
		else
			blueCount++;
		return;
	}

	int color = paper[start.i][start.j];
	bool isOne = isOnePaper(start, end, color);

	if (isOne) {
		if (color == WHITE) {
			whiteCount++;
		}
		else if (color == BLUE) {
			blueCount++;
		}
		return;
	}

	Point mid = Point((start.i + end.i) / 2, (start.j + end.j) / 2);

	countPaper(start, mid);
	countPaper(mid, end);
	countPaper(Point(start.i, mid.j), Point(mid.i, end.j));
	countPaper(Point(mid.i, start.j), Point(end.i, mid.j));

	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	Point start = Point(0 ,0);
	Point end = Point(N, N);

	countPaper(start, end);

	cout << whiteCount << "\n" << blueCount << "\n";


	return 0;
}
