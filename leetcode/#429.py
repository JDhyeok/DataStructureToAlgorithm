"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        
        if root == None:
            return []
        
        ret = []
        q = deque()
        
        ret.append([root.val])
        q.append(root)
        
        while len(q) != 0:
            N, tmp = len(q), []
            
            for i in range(N):
                node = q.popleft()
                
                for child in node.children:
                    tmp.append(child.val)
                    q.append(child)
            if len(tmp) != 0:
                ret.append(tmp)
        
        return ret