"""
Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.
"""

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        charToWord, wordToChar = {}, {}
        words = s.split(' ')

        if len(pattern) != len(words):
            return False
        
        for c, w in zip(pattern, words):
            if ((c in charToWord and charToWord[c] != w) or 
                (w in wordToChar and wordToChar[w] != c)):
                return False
            
            charToWord[c] = w
            wordToChar[w] = c

        return True