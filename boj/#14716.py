from collections import deque

way = [[0, 1], [1, 0], [-1, 0], [0, -1], [1, 1], [-1, -1], [-1, 1], [1, -1]]

def bfs(point):
    q = deque()

    q.append(point)
    board[point[0]][point[1]] = 0
    
    while len(q) > 0:
        curi, curj = q.popleft()

        for i, j in way:
            nexti, nextj = curi + i, curj + j

            if nexti < 0 or nextj < 0 or nexti >= N or nextj >= M:
                continue

            if board[nexti][nextj] == 1:
                board[nexti][nextj] = 0
                q.append([nexti, nextj])

        
   

N, M = list(map(int, input().split()))

board = [list(map(int, input().split())) for _ in range(N)]

ans = 0

for i in range(0, N):
    for j in range(0, M):
        if board[i][j] == 1:
            bfs([i, j])
            ans += 1

print(ans)