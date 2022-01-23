N = int(input())

ppl, ans = [], []

for i in range(0, N):
    ppl.append(list(map(int, input().split())))


for me in ppl:
    cnt = 0

    for other in ppl:
        if me[0] < other[0] and me[1] < other[1]:
            cnt += 1
    ans.append(cnt + 1)

for a in ans:
    print(a, end=" ")