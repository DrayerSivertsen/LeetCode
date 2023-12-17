"""
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
"""

class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i, j = 0, 0

        while i < len(s) and j < len(t):
            if s[i] == t[j]:
                i += 1

            j += 1

        return True if i == len(s) else False






# My solution
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        l, r = 0, 0

        if len(s) == 0:
            return True

        while l < len(t):
            r = l
            i = 0

            while r < len(t) and i < len(s):
                if t[r] == s[i]:
                    r += 1
                    i += 1
                else:
                    r += 1

            if s[i-1] == t[r-1] and i == len(s):
                return True

            l += 1

        return False                
