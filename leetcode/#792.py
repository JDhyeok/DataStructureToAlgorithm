class Solution(object):
    def numMatchingSubseq(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: int
        """
        word_dict = defaultdict(list)
        
        for word in words:
            word_dict[word[0]].append(word)
            
        ans = 0
        
        for ch in s:
            
            candidate_sub_words = word_dict[ch]
            word_dict[ch] = []
            
            for cand_word in candidate_sub_words:
                if len(cand_word) == 1:
                    ans += 1
                else:
                    word_dict[cand_word[1]].append(cand_word[1:])
                    
        return ans