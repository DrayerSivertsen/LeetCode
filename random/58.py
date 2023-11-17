"""
Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.
"""


class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        res = 0
        i = len(s) - 1

        # skip spaces
        while s[i] == ' ':
            i -= 1

        # count word
        while i >= 0 and s[i] != ' ':
            res += 1
            i -= 1

        return res
            


# correct solution but doesn't use algorithm
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip().split(' ') # split words

        return len(s[-1]) # return last word