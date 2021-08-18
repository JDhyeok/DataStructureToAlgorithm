#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

#define ERROR 987654321

int N, one = 0, zero = 0, mi = 0;
short paper[2187][2187];

void solver(int x, int y, int k);

int main() {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int k;

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}
	
	for (int i = 0; i < 8; i++) 
		if (int(pow(3, i)) == N)
			k = i;

	solver(0, 0, k);

	cout << mi << "\n" << zero << "\n" << one << "\n";

	return 0;
}

int check(int x, int y, int threshold) {
	int tmp = paper[x][y];
	for (int i = x; i < x + threshold; i++) {
		for (int j = y; j < y + threshold; j++) {
			if (tmp != paper[i][j])
				return ERROR;
		}
	}
	return tmp;
}

void solver(int x, int y, int k) {
	int threshold = pow(3, k);
	int add = pow(3, k - 1);

	for (int i = x; i < x + threshold; i += threshold) {
		for (int j = y; j < y + threshold; j += threshold) {

			int tmp = check(i, j, threshold);
			if (tmp == 1)
				one++;
			else if (tmp == 0)
				zero++;
			else if (tmp == -1)
				mi++;
			else {
				for (int p = x; p < x + threshold; p += add) {
					for (int q = y; q < y + threshold; q += add) {

						solver(p, q, k - 1);
					}
				}
			}
		}
	}
}