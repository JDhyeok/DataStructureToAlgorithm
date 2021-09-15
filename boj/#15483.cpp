#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 1001

int dp[MAX][MAX];

void init() {
	// 2차원 배열의 첫 행, 열 초기화
	for (int i = 0; i < MAX; i++) {
		dp[0][i] = i;
		dp[i][0] = i;
	}
}

void levenshtein(string str1, string str2) {
	init();

	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
			else {
				dp[i][j] = min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str1;
	string str2;

	cin >> str1 >> str2;

	levenshtein(str1, str2);

	cout << dp[str1.size()][str2.size()] << "\n";
	
	return 0;
}
