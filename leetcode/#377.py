class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = [0]*(target + 1)
        
        for i in range(1, len(dp)):
            tmp = 0
            for n in nums:
                if i == n:
                    tmp += 1
                elif i > n:
                    tmp += dp[i - n]
                    
            dp[i] = tmp
                   
        return dp[target]