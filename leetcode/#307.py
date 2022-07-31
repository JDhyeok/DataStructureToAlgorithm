class NumArray(object):

    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        self.nums = nums
        self.num_sum = sum(nums)
        self.length = len(nums)

    def update(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """
        self.num_sum -= (self.nums[index] - val)
        self.nums[index] = val
        
    def sumRange(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: int
        """
        if right - left > self.length // 2:
            ans = sum(self.nums[:left]) + sum(self.nums[right + 1:])
            return self.num_sum - ans
        else:
            return sum(self.nums[left:right + 1])
        

# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# obj.update(index,val)
# param_2 = obj.sumRange(left,right)