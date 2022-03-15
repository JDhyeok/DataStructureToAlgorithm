S = int(input())

ans = 0
sm = 0

for i in range(1, S+1):
    sm += i
    ans += 1
    if S < sm:
       break 

print(ans - 1)