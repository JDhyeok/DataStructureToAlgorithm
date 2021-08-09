#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<math.h>

using namespace std;

int N, M;
bool nums[11];
int ans = 999999999;

int press(int n) {
	int cnt = 0;
	if (n == 0) {
		if (nums[n])
			return 1;
	}
	while (n) {

		int i = n % 10;
		if (!nums[i])
			return 0;
		n /= 10;
		cnt++;
	}
	return cnt;
}

int main() {
	fill_n(nums, 11, true);

	int hundred = 100;

	cin >> N >> M;
	int tmp;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		nums[tmp] = false;
	}

	for (int i = 0; i <= 10000000; i++) {
		tmp = press(i);


		if (tmp + abs(N - i) < ans && tmp) {
			ans = tmp + abs(N - i);
		}
	}
	cout << min(ans, abs(hundred-N));

	return 0;
}