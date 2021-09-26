#include<iostream>
#include<algorithm>
#include<string>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

int T, N;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int ans = 1;
	unordered_map<string, int> types;

	cin >> T;

	string a, b;
	while (T--) {
		ans = 1;
		cin >> N;
		
		types.clear();

		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			types[b]++;
		}

		unordered_map<string, int>::iterator it = types.begin();

		for (it; it != types.end(); it++) {
			ans *= (it->second + 1);
		}
		cout << ans - 1 << "\n";
	}
	
	
	return 0;
}