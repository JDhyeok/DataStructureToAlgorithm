class Solution:
    def smallestRangeI(self, nums: List[int], k: int) -> int:
        num_min, num_max = min(nums), max(nums)

        num_max -= k
        num_min += k

        if num_max - num_min < 0:
            return 0
            
        return num_max - num_min