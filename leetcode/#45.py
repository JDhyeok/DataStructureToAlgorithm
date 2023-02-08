# O(N^2) Solution
class Solution:
    def jump(self, nums: List[int]) -> int:
        N = len(nums)
        dp = [987654321] * N
        dp[0] = 0

        for i in range(N):
            max_j = nums[i]

            for j in range(1, max_j + 1):
                if i + j >= N:
                    break
                dp[i + j] = min(dp[i + j], dp[i] + 1)
        
        return dp[N - 1]

# Better Time Complexity O(N)!!!
class Solution:
    def jump(self, nums: List[int]) -> int:
        N = len(nums)
        ans, availFarthest, curFarIdx = 0, 0, 0

        for i in range(N - 1):
            availFarthest = max(availFarthest, i + nums[i])

            if i == curFarIdx:
                ans += 1
                curFarIdx = availFarthest

        return ans