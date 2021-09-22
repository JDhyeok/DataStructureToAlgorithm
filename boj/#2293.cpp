#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<math.h>
#include<string>
#include<unordered_map>
#include<map>

using namespace std;

#define N_MAX 101
#define K_MAX 10001

int N, K;
int coin[N_MAX];
int dp[K_MAX];



int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> coin[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j >= coin[i]) {
                dp[j] += dp[j - coin[i]];
            }
        }
    }

    cout << dp[K] << "\n";

    return 0;
}
