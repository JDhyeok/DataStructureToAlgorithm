class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        # 77ms / 14.5MB
        # return (sorted(s) == sorted(t))
        
        s_dict, t_dict = defaultdict(int), defaultdict(int)
        
        for ch in s:
            s_dict[ch] = s_dict.get(ch, 0) + 1
        for ch in t:
            t_dict[ch] = t_dict.get(ch, 0) + 1
            
        return (s_dict == t_dict)
        