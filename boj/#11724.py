from collections import defaultdict

def dfs(cur):
    visited[cur] = True
    for nex in adj_list[cur]:
        if visited[nex] == False:
            dfs(nex)

N, M = list(map(int, input().split()))

adj_list = defaultdict(list)
visited = [False] * (N + 1)

for _ in range(M):
    u, v = list(map(int, input().split()))
    adj_list[u].append(v)
    adj_list[v].append(u)

ans = 0

for i in range(1, N + 1):
    if visited[i] == False:
        ans += 1
        dfs(i)

print(ans)