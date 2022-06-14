N, M, B = list(map(int,input().split()))

blocks = []

for _ in range(N):
    tmp = list(map(int,input().split()))
    blocks.append(tmp)

min_time, height = 987654321, 0

for cur_height in range(257):
    
    removed, added = 0, 0

    for i in range(N):
        for j in range(M):
            if blocks[i][j] < cur_height:
                added += cur_height - blocks[i][j]
            elif blocks[i][j] > cur_height:
                removed += blocks[i][j] - cur_height
    
    if B + removed < added:
        continue

    if (removed * 2) + added <= min_time:
        min_time = (removed * 2) + added
        height = cur_height

print(min_time, height)