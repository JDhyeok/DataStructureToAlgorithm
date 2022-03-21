A, B = input(), input()

a_len, b_len = len(A), len(B)

ans, dp = 0, [[0 for i in range(b_len + 1)] for j in range(a_len + 1)]

for i in range(1, a_len + 1):
    for j in range(1, b_len + 1):
        if A[i - 1] == B[j - 1]:
            dp[i][j] = dp[i-1][j-1] + 1
            ans = max(ans, dp[i][j])

print(ans)