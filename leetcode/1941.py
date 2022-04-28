# one line code
# 22 ms / 13.7 MB
class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        return len(set(Counter(s).values())) == 1

# 24 ms / 13.4 MB
class Solution(object):
    def areOccurrencesEqual(self, s):
        """
        :type s: str
        :rtype: bool
        """
        max_num = 0
        dic = {}
        
        for ch in s:
            dic[ch] = dic.get(ch, 0) + 1
            max_num = max(max_num, dic[ch])
            
        for k, v in dic.items():
            if v != max_num:
                return False
            
        return True
        