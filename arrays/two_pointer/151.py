"""
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
"""

class Solution:
    def reverseWords(self, s: str) -> str:
        res, i = '', 0

        while i < len(s):
            # skip spaces
            while i < len(s) and s[i] == ' ':
                i += 1
                
            # exit if at end (to avoid extra space)
            if i >= len(s): break
            j = i + 1
            
            # end of word
            while j < len(s) and s[j] != ' ':
                j += 1

            sub = s[i:j]

            if len(res) == 0:
                res = sub
            else:
                res = sub + ' ' + res
            i = j + 1

        return res




# My Solution
class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s)
        i = 0
        while i < len(s):
            j = i
            # skip spaces
            while j < len(s) and s[j] == ' ':
                j += 1
            i = j
            
            # end of word
            while j < len(s) and s[j] != ' ':
                j += 1
                
            j -= 1
            end_word = j

            # swap letters
            while i < j:
                temp = s[i]
                s[i] = s[j]
                s[j] = temp
                i += 1
                j -= 1

            if end_word > i:
                i = end_word
            else:
                i += 1
        s.reverse()
        s = ''.join(s)
        return ' '.join(s.split())

            