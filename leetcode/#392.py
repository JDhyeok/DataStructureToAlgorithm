class Solution(object):
    def isSubsequence(self, s, t):
        
        letters = iter(t)
        
        for c in s:
            if c not in letters:
                return False
            
        return True