class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        
        ans = ''

        for i in range(min(len(str1), len(str2))):
            tmp = str1[0:i + 1]

            if (len(str1) % len(tmp)) != 0 or (len(str1) % len(tmp)) != 0:
                continue
                
            if str1 == tmp*(len(str1) // len(tmp)) and str2 == tmp*(len(str2) // len(tmp)):
                ans = tmp

        return ans