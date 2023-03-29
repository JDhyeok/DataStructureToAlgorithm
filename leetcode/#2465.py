class Solution:
    def distinctAverages(self, nums: List[int]) -> int:
        nums = sorted(nums)
        
        i, j = 0, len(nums) - 1

        ave_list = []
        while i < j:
            
            ave_list.append((nums[i] + nums[j]) / 2)

            i += 1
            j -= 1
        return len(list(set(ave_list)))