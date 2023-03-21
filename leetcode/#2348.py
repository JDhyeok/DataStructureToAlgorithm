class Solution:
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        ret, cnt = 0, 0
        
        for num in nums:
            if num != 0:
                ret += (cnt*(cnt+1)) // 2
                cnt = 0
            elif num == 0:
                cnt += 1
        ret += (cnt*(cnt+1)) // 2
        return ret