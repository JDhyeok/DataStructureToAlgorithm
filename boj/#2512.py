
N = int(input())
nums = list(map(int, input().split()))
M = int(input())

l, r = 0, max(nums)

ans = 0
while l <= r:
    mid = (l + r) // 2
    num_sum = 0

    for n in nums:
        if n < mid:
            num_sum += n
        else:
            num_sum += mid
    
    if num_sum <= M:
        ans = mid
        l = mid + 1
    elif num_sum > M:
        r = mid - 1

print(ans)