# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        def checkSymmetric(node1, node2):
            # 둘 중 하나만 None인 경우 False
            if node1 == None or node2 == None:
                return node1 == node2
            
            # 둘 다 None이 아닌 경우
            if node1.val == node2.val:
                return checkSymmetric(node1.left, node2.right) and checkSymmetric(node1.right, node2.left)
                
            return False

        return checkSymmetric(root.left, root.right)