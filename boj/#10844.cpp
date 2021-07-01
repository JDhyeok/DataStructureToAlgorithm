#include<iostream>

using namespace std;

#define MOD 1000000000

int main()
{
    long long dp[101][11];

    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i < 101; i++) {
        for (int j = 0; j < 10; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            }
            else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            }
            else {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
            }
        }
    }
    int n;
    cin >> n;

    long long ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += dp[n][i];
    }

    cout << ans % MOD;

    return 0;
}
