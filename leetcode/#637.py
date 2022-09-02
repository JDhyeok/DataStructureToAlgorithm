# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        
        ans, q = [], deque()

        q.append(root)
        
        while len(q) != 0:
            val_sum, N = 0, len(q)
            
            for _ in range(N):
                cur = q.popleft()
                val_sum += cur.val
                
                if cur.left != None:
                    q.append(cur.left)
                if cur.right!= None:
                    q.append(cur.right)
                    
            ans.append(val_sum / N)
        
        return ans
            