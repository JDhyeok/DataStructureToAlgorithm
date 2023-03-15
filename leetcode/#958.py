# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isCompleteTree(self, root: Optional[TreeNode]) -> bool:

        q = deque()
        q.append(root)

        is_null = False
        while len(q) != 0:
            cur = q.popleft()

            if cur == None:
                is_null = True
            else:
                if is_null:
                    return False
                q.append(cur.left)
                q.append(cur.right)
                
        return True