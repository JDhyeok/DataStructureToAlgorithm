from collections import deque

way = [[0, 1], [1, 0], [-1, 0], [0, -1]]


def BFS(i, j):
    size = 1

    q = deque()
    board[i][j] = 0
    q.append([i, j])

    while len(q) > 0:
        curi, curj = q.popleft()

        for di, dj in way:
            nexti, nextj = curi + di, curj + dj

            if nexti < 0 or nextj < 0 or nexti >= N or nextj >= M:
                continue

            if board[nexti][nextj] == 1:
                size += 1
                board[nexti][nextj] = 0
                q.append([nexti, nextj])

    return size



N, M = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(N)]

pic_cnt = 0
pic_max = 0

for i in range(0, N):
    for j in range(0, M):
        if board[i][j] == 1:
            pic_cnt += 1
            pic_max = max(pic_max, BFS(i, j))

print(pic_cnt)
print(pic_max)