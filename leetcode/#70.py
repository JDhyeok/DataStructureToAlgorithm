class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [i for i in range(n + 1)]
        
        dp[1] = 1
        dp[2] = 2
        
        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]
        
        return dp[n]

    # def climbStairs(self, n):
    #     if n == 1:
    #         return 1
    #     elif n == 2:
    #         return 2

    #     return climbStairs(n - 1) + climbStairs(n - 2)