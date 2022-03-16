op = {')':'(', '}':'{', ']': '['}

while True :
    S = input()
    stack = []

    if S == "." :
        break

    flag = True
    for ch in S:
        if ch in op:
            if len(stack) > 0 and op[ch] == stack[-1]:
                stack.pop()
            else:
                flag = False
                break
        elif ch in ['(', '{', '[']:
            stack.append(ch)
    

    print('yes') if flag == True and len(stack) == 0 else print('no')
    