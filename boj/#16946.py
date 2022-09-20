from collections import deque

def bfs(strt_i, strt_j):
    
    
    dirs = [[0, 1], [1, 0], [-1, 0], [0, -1]]
    
    q = deque()
    q.append([strt_i, strt_j])
    board[strt_i][strt_j] = '-'
    
    cnt = 1
    walls = []
    
    while len(q) != 0:
        cur = q.popleft()
        cur_i, cur_j = cur[0], cur[1]
        
        for d in dirs:
            next_i, next_j = cur_i + d[0], cur_j + d[1]
            
            if next_i < 0 or next_j < 0 or next_i >= N or next_j >= M or board[next_i][next_j] == '-'or board[next_i][next_j] == '+':
                continue
            
            if board[next_i][next_j] == '1':
                walls.append([next_i, next_j])
                board[next_i][next_j] = '+'
                continue
            
            q.append([next_i, next_j])
            board[next_i][next_j] = '-'
            cnt += 1
    
    
    for wall in walls:
        board[wall[0]][wall[1]] = '1'
        answer[wall[0]][wall[1]] += cnt
            

N, M = list(map(int, input().split()))
board = []
answer = [[0]*M for _ in range(N)]

for _ in range(N):
    line = input()
    board.append(list(line))

ways = []
for i in range(N):
    for j in range(M):
        if board[i][j] == '0':
            ways.append([i, j])


for way in ways:
    if board[way[0]][way[1]] == '0':
        bfs(way[0],way[1])
    
for i in range(N):
    for j in range(M):
        if board[i][j] == '1':
            answer[i][j] += 1
            answer[i][j] %= 10

for ans in answer:
    print(''.join(map(str,ans)))