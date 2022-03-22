class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if len(nums) == 0:
            return ""
        
        ans = []
        min_num, max_num = nums[0], nums[0]
        flag = False
        
        for i in range(1, len(nums)):
            if nums[i - 1] + 1 != nums[i]:
                if min_num == max_num:
                    ans.append(str(min_num))
                else:
                    ans.append(str(min_num) + "->" + str(max_num))
                    
                min_num, max_num = nums[i], nums[i]
            else:
                max_num = nums[i]
        
        if min_num == max_num:
            ans.append(str(min_num))
        else:
            ans.append(str(min_num) + "->" + str(max_num))
            
        return ans