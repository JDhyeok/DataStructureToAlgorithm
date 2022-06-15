# Three Solution

class Solution(object):
    def containsDuplicate(self, nums):
        """ Sort the array
        Time Complexity : O(NlogN) / Space Complexity : O(1)
        """
        nums = sorted(nums)
        for i in range(len(nums) - 1):
            if nums[i] == nums[i + 1]:
                return True

        return False

class Solution(object):
    def containsDuplicate(self, nums):
        """ Use hash for searching frequency
        Time Complexity : O(N) / Space Complexity : O(N)
        """
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1
            if freq[num] > 1:
                return True

        return False

class Solution(object):
    def containsDuplicate(self, nums):
        """ Use python Set
        Time Complexity : O(N) / Space Complexity : O(N)
        """
        return len(set(nums)) != len(nums)