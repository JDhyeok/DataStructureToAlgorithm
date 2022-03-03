"""
O(N^3) 완전탐색
i = 0, j = 1로 시작
나누는 지점 : 0 ~ 시작, 시작 + 1 ~ 다음, 다음 + 1 ~ 끝
"""

word = input()
ans = "z" * 50

for i in range(0, len(word) - 1):
    for j in range(i + 1, len(word) - 1):
        a = word[0:i+1][::-1]
        b = word[i+1:j+1][::-1]
        c = word[j+1:][::-1]

        new_word = a + b + c

        if new_word < ans:
            ans = new_word

print(ans)


    
