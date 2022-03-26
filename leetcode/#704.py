class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        if target < nums[0] or target > nums[-1]:
            return -1
        
        l, mid, r = 0, 0, len(nums)
        
        while l <= r:
            
            mid = int((l + r) / 2)
            
            if nums[mid] < target:
                l = mid + 1
            elif nums[mid] > target:
                r = mid - 1
            else:
                break
        
        return mid if nums[mid] == target else -1