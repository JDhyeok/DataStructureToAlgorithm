from collections import deque
import copy

N = int(input())

INF = 987654321
dp = [INF for _ in range(N + 1)]

dp[N] = 0

i = N - 1

while i >= 1:
    dp[i] = min(dp[i], dp[i + 1] + 1)
    if i * 2 <= N:
        dp[i] = min(dp[i], dp[i * 2] + 1)
    if i * 3 <= N:
        dp[i] = min(dp[i], dp[i * 3] + 1)
        
    i -= 1
    
q = deque()
q.append([1])
while len(q) != 0:
    cur = q.popleft()

    if cur == None:
        break
    cur_idx = cur[-1]
    
    if cur_idx == N:
        print(dp[1])
        print(' '.join(list(map(str, sorted(cur, reverse=True)))))
        break
    
    if cur_idx + 1 <= N and dp[cur_idx] - 1 == dp[cur_idx + 1]:
        tmp = copy.deepcopy(cur)
        tmp.append(cur_idx + 1)
        q.append(tmp)
    if cur_idx * 2 <= N and dp[cur_idx] - 1 == dp[cur_idx * 2]:
        tmp = copy.deepcopy(cur)
        tmp.append(cur_idx * 2)
        q.append(tmp)
    if cur_idx * 3 <= N and dp[cur_idx] - 1 == dp[cur_idx * 3]:
        tmp = copy.deepcopy(cur)
        tmp.append(cur_idx * 3)
        q.append(tmp)
        
        
