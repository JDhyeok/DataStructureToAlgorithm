class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False

        N, ret = len(s1), False

        s1_dict = defaultdict(int)

        for ch in s1:
            s1_dict[ch] += 1

        for i in range(len(s2) - N + 1):
            substr = s2[i:i + N]

            flag = False
            substr_dict = defaultdict(int)
            for ch in substr:
                substr_dict[ch] += 1
            
            if s1_dict == substr_dict:
                flag = True
            
            ret |= flag

        return ret