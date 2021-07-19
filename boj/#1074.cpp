#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main() {

	int N, r, c;

	cin >> N >> r >> c;
	
	int ans = 0;

	int y = pow(2, N) / 2;
	int x = y;

	while (N-- > 0) {
		int block = pow(4, N);
		int mid = pow(2, N) / 2;

		if (r < y && c < x) {
			x -= mid;
			y -= mid;
		}
		else if (r < y && c >= x) {
			x += mid;
			y -= mid;
			ans += block;
		}
		else if (r >= y && c < x) {
			x -= mid;
			y += mid;
			ans += block*2;
		}
		else {
			x += mid;
			y += mid;
			ans += block * 3;
		}
	}

	cout << ans;

	return 0;
}