class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        # 44ms / 13.3 MB
        # dp = [[0]*n for _ in range(m)]
        
        # for i in range(m):
        #     for j in range(n):
        #         if i == 0 or j == 0:
        #             dp[i][j] = 1
        #         else:
        #             dp[i][j] = dp[i-1][j] + dp[i][j-1]
        
        # return dp[m-1][n-1]
        
        # 37ms / 13.3MB
        dp = [1]*n
        
        for _ in range(m - 1):
            for i in range(1, n):
                dp[i] = dp[i] + dp[i - 1]

        return dp[-1]