def preorder(node):
    if node != '.':
        print(node, end='')
        preorder(adj_list[node][0])
        preorder(adj_list[node][1])

def inorder(node):
    if node != '.':
        inorder(adj_list[node][0])
        print(node, end='')
        inorder(adj_list[node][1])

def postorder(node):   
    if node != '.': 
        postorder(adj_list[node][0])
        postorder(adj_list[node][1])
        print(node, end='')

N = int(input())

adj_list = {}

for _ in range(N):
    nodes = list(input().split())
    adj_list[nodes[0]] = nodes[1:]

preorder('A')
print()
inorder('A')
print()
postorder('A')