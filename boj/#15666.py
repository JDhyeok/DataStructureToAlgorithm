
def dfs(depth):
    if len(tmp) == M:
        print(" ".join(map(str, tmp)))
        return

    for i in range(len(nums)):
        if depth == 0 or tmp[-1] <= nums[i]:
            tmp.append(nums[i])
            dfs(depth + 1)
            tmp.pop()
    



N, M = list(map(int, input().split()))
nums = list(map(int, input().split()))

nums = sorted(list(set(nums)))
tmp = []

dfs(0)

