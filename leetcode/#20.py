class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        
        d = {'(':')', '{':'}','[':']'}
        stack = []
        
        for i in s:
            if i in d:
                stack.append(i)
            elif len(stack) == 0 or d[stack.pop()] != i:
                return False
            
        return len(stack) == 0
    
#         q = deque()
        
#         for ch in s:
#             if ch in ['(', '{', '[']:
#                 q.append(ch)
#             else:
#                 if len(q) == 0:
#                     return False
                
#                 cur = q.pop()
#                 if cur == '(' and ch != ')':
#                     return False
#                 elif cur == '{' and ch != '}':
#                     return False
#                 elif cur == '[' and ch != ']':
#                     return False
#         if len(q) > 0:
#             return False
#         return True
                    