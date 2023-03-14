# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        global ans
        ans = 0

        def dfs(num, cur):
            if cur == None:
                return

            global ans
            
            num = num * 10 + cur.val
            print(num)
            dfs(num, cur.left)
            dfs(num, cur.right)
            if cur.left == None and cur.right == None:
                ans += num
                return
            num //= 10

        dfs(0, root)
        return ans
