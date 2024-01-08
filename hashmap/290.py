"""
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
"""

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        mapPS, mapSP = {}, {}
        words = s.split(' ')

        if len(pattern) != len(words):
            return False
        
        for c, word in zip(pattern, words):
            if ((c in mapPS and mapPS[c] != word) or 
                (word in mapSP and mapSP[word] != c)):
                return False
            
            mapPS[c] = word
            mapSP[word] = c

        return True