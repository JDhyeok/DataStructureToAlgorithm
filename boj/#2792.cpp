#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int N, M;
int jewly[300001];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;


	int l = 1, r = 1;
	for (int i = 0; i < M; i++) {
		cin >> jewly[i];
		r = max(r, jewly[i]);
	}

	int ans = 0;

	while (l <= r) {
		int mid = (l + r) / 2;

		// 보석을 나눠줄 수 있는 최소 사람
		int max_man = 0, mod = 0;
		for (int i = 0; i < M; i++) {
			max_man += jewly[i] / mid;
			if (jewly[i] % mid > 0)
				mod++;
		}


		if (max_man + mod > N) {
			
			l = mid + 1;
		}
		else if (max_man + mod <= N) {
			ans = mid;
			r = mid - 1;
		}
	}

	cout << ans;

	return 0;
}