N, S = list(map(int,input().split()))
nums = list(map(int,input().split()))

ans = 0

def dfs(num_sum, idx):
    global ans

    if idx >= len(nums):
        return

    num_sum += nums[idx]

    if num_sum == S:
        ans += 1

    dfs(num_sum - nums[idx], idx + 1)
    dfs(num_sum, idx + 1)
    

dfs(0, 0)

print(ans)