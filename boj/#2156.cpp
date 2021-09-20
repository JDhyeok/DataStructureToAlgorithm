#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>

using namespace std;

#define MAX 10001

int n;
int wine[MAX];
int dp[MAX + 1];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> wine[i];
    
    int ans = 0;

    if (n == 1)
        ans = wine[1];
    else if (n >= 2) {
        dp[1] = wine[1];
        dp[2] = wine[1] + wine[2];
        ans = dp[2];
    }
    
    for (int i = 3; i <= n; i++) {
        int tmp1 = dp[i - 3] + wine[i - 1] + wine[i];
        int tmp2 = dp[i - 2] + wine[i];
        int tmp3 = dp[i - 1];
        dp[i] = max(tmp3, max(tmp1, tmp2));
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";

    return 0;
}
