class Solution:
    def findComplement(self, num: int) -> int:
        idx = 1
        while num >= idx:
            num ^= idx
            idx <<= 1
            
        return num