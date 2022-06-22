# expr = input()

# expr_list = []

# tmp = ''
# for ch in expr:
#     if ch.isdigit() == True:
#         tmp += ch
#     else:
#         expr_list.append(tmp)
#         expr_list.append(ch)
#         tmp = ''
# expr_list.append(tmp)

# ans = 0

# flag = 1
# for element in expr_list:
#     if element == '-':
#         flag = -1

#     if element.isdigit() == True:
#         ans += flag * int(element)

# print(ans)


### More Python'st code
expr = input().split('-')

num = []

for ex in expr:
    num.append(sum(list(map(int, ex.split('+')))))

print(num[0] - sum(num[1:]))