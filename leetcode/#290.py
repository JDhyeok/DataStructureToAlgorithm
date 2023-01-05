class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        word_list = s.split()
        pat2word_dict, word2pat_dict = {}, {}
        if len(pattern) != len(word_list):
            return False

        for idx in range(len(pattern)):
            if pat2word_dict.get(pattern[idx]) == None and word2pat_dict.get(word_list[idx]) == None:
                pat2word_dict[pattern[idx]] = word_list[idx]
                word2pat_dict[word_list[idx]] = pattern[idx]
            
            if pat2word_dict.get(pattern[idx]) == None and word2pat_dict.get(word_list[idx]) != None:
                return False

            if pat2word_dict.get(pattern[idx]) != None and word2pat_dict.get(word_list[idx]) == None:
                return False

            elif pat2word_dict[pattern[idx]] != word_list[idx] or word2pat_dict[word_list[idx]] != pattern[idx]:
                return False

        return True