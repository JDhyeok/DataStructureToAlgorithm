class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        global ans
        ans = 0
        def devide(l, r):
            global ans
            if l == r:
                if l % 2 == 0:
                    ans += nums[l]
                else:
                    ans -= nums[l]

            if l < r:
                mid = (l + r) // 2
                devide(l, mid)
                devide(mid + 1, r)

        
        left, right = 0, len(nums) - 1
        devide(left, right)

        return abs(ans)


# Better Solution Binary Search O(logN)
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return nums[0]
        l, r = 0, len(nums) - 1

        if nums[0] != nums[1]:
            return nums[0]
        if nums[r] != nums[r - 1]:
            return nums[r]

        while l <= r:
            mid = (l + r) // 2

            if nums[mid] != nums[mid - 1] and nums[mid] != nums[mid + 1]:
                    return nums[mid]
            elif (nums[mid] == nums[mid + 1] and mid % 2 == 0) or (nums[mid] == nums[mid - 1] and mid % 2 != 0):
                l = mid + 1
            else:
                r = mid - 1

        return nums[l]