#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

bool isPalindrome(string s) {
	int i = 0;
	int j = s.size() - 1;
	while (i <= j) {
		if (s[i] != s[j])
			return false;
		i++; j--;
	}

	return true;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans = 0;
	string s;

	cin >> s;

	for (int i = s.size() - 1; i >= 0; i--) {
		string tmp = s.substr(i, s.size());
		if (isPalindrome(tmp)) {
			ans = s.size() + i;
		}
	}

	cout << ans;
	
	return 0;
}
