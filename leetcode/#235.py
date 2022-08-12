# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        trav1, trav2, ans = root, root, root
        
        while trav1 != p or trav2 != q:
            if trav1 == trav2:
                ans = trav1
            
            if trav1.val < p.val:
                trav1 = trav1.right
            elif trav1.val > p.val:
                trav1 = trav1.left
            
            if trav2.val < q.val:
                trav2 = trav2.right
            elif trav2.val > q.val:
                trav2 = trav2.left
        
        return ans