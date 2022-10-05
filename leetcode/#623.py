# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        
        def dfs_add(node, dpth, d):
            if node == None and dpth == depth:
                return TreeNode(val)
            elif node == None:
                return None
            
            if dpth == depth and d == 0:
                tmp = TreeNode(val, node, None)
                return tmp
            if dpth == depth and d == 1:
                tmp = TreeNode(val, None, node)
                return tmp
            node.left = dfs_add(node.left, dpth + 1, 0)
            node.right = dfs_add(node.right, dpth + 1, 1)

            return node
        if depth == 1:
            return TreeNode(val, root, None)
        dfs_add(root, 1, 0)
        return root