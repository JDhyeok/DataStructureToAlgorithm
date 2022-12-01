class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        
        mid = len(s) // 2
        
        fhalf = s[:mid]
        shalf = s[mid:]
        
        fhalf_vowel_cnt, shalf_vowel_cnt = 0, 0
        
        for c in fhalf:
            if c in vowels:
                fhalf_vowel_cnt += 1
        for c in shalf:
            if c in vowels:
                shalf_vowel_cnt += 1
                
        return fhalf_vowel_cnt == shalf_vowel_cnt