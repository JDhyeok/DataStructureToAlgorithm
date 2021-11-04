#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N, ans = 0;
string str;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	while (N--) {

		cin >> str;
		
		int mask = 0;
		bool flag = true;

		for (int i = 0; i < str.size(); i++) {
			if ((mask & (1 << (str[i] - 'a'))) > 0) {
				// 이미 한 번 나온 문자다
				if (str[i - 1] != str[i]) {
					// 이전 문자와 같지 않다
					flag = false;
					break;
				}

			}
			else {
				// 나온적이 없는 문자다
				mask |= 1 << (str[i] - 'a');
			}
		}

		if (flag)
			ans++;
	}

	cout << ans;
	
	return 0;
}
