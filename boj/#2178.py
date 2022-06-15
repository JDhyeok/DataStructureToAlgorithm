from collections import deque

def bfs(board, N, M):
    dir = [[0, 1], [1, 0], [-1, 0], [0, -1]]

    q = deque()
    q.append([0, 0, 1])

    while len(q) != 0:
        cur_i, cur_j, cnt = q.popleft()

        for d in dir:
            next_i, next_j = cur_i + d[0], cur_j + d[1]

            if next_i < 0 or next_j < 0 or next_i >= N or next_j >= M or board[next_i][next_j] == 0:
                continue

            if board[next_i][next_j] == 1:
                board[next_i][next_j] = cnt + 1
                q.append([next_i, next_j, cnt + 1])

    return board[N-1][M-1]

N, M = list(map(int, input().split()))

board = []

for _ in range(N):
  board.append(list(map(int, input())))

print(bfs(board, N, M))
