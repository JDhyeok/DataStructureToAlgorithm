answer = [1, 2, 3, 4, 5]

nums = list(map(int,input().split()))

while answer != nums:
    for i in range(1, len(nums)):
        if nums[i - 1] > nums[i]:
            nums[i], nums[i - 1] = nums[i - 1], nums[i]
            print(' '.join(map(str, nums)))
            