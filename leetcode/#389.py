class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        
        ret = 0
        
        for ch in s:
            ret ^= ord(ch)
        
        for ch in t:
            ret ^= ord(ch)
            
        return ret
        
#         s = sorted(s)
#         t = sorted(t)
        
#         for i in range(len(s)):
#             if s[i] != t[i]:
#                 return t[i]
            
#         return t[-1]