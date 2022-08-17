class Solution(object):
    def uniqueMorseRepresentations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        morse_code = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        
        
        
        morse_list = []
        
        for word in words:
            morse = ''
            for ch in word:
                idx = ord(ch) - ord('a')
                morse += morse_code[idx]
            morse_list.append(morse)
            
        return len(list(set(morse_list)))
            
            