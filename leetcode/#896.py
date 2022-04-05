class Solution(object):
    def isMonotonic(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return True
        
        desc, asc = False, False
        
        for i in range(1, len(nums)):
            if nums[i-1] == nums[i]:
                continue
            
            if nums[i-1] < nums[i]:
                asc = True
            elif nums[i-1] > nums[i]:
                desc = True
                
            if asc == desc:
                return False
            
        return True