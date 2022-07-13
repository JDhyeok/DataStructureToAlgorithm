# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        
        ans, q = [], [root]
        
        while len(q) > 0:
            num, tmp = len(q), []
            for _ in range(num):
                cur = q[0]
                q.pop(0)
                tmp.append(cur.val)
                
                if cur.left != None:
                    q.append(cur.left)
                if cur.right != None:
                    q.append(cur.right)
            ans.append(tmp)
            
        return ans