s = list(input().rstrip())

idx = 0

while idx < len(s):
    if s[idx] == '<':
        idx += 1
        while s[idx] != '>':
            idx += 1
        idx += 1
    elif s[idx].isalnum():
        strt = idx
        while idx < len(s) and s[idx].isalnum():
            idx += 1
        tmp = s[strt:idx]
        tmp = reversed(tmp)
        s[strt:idx] = tmp
    else:
        idx += 1

print(''.join(s))