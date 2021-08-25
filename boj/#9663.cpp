#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int N, ans = 0;

int queen[16];

bool isGood(int);
void solver(int);

void solver(int index) {
	// base case
	if (index >= N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		queen[index] = i;
		
		if (isGood(index))
			solver(index + 1);

		
	}
}

bool isGood(int idx) {
	for (int i = 0; i < idx; i++) {
		if (queen[idx] == queen[i] || idx - i == abs(queen[idx] - queen[i]))
			return false;
	}
	return true;
}

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> N;

	solver(0);


	cout << ans << "\n";

	return 0;
}
