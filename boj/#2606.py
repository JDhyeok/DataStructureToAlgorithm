from collections import deque

def bfs():
    
    ans = 0
    q = deque()

    visited[1] = True
    q.append(1)

    while len(q) != 0:
        cur = q.popleft()

        for edge in adj_list:
            if edge[0] == cur and visited[edge[1]] == False:
                visited[edge[1]] = True
                ans += 1
                q.append(edge[1])
            elif edge[1] == cur and visited[edge[0]] == False:
                visited[edge[0]] = True
                ans += 1
                q.append(edge[0])

    return ans
    

N = int(input())
M = int(input())

adj_list = []
visited = [False for _ in range(N + 1)]

for _ in range(M):
    adj_list.append(list(map(int, input().split())))

print(bfs())