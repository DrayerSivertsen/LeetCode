"""
Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
"""


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        cache = [[-1] * len(text2) for _ in range(len(text1))]

        def helper(s1, s2, i1, i2, cache):
            if i1 == len(s1) or i2 == len(s2):
                return 0

            if cache[i1][i2] != -1:
                return cache[i1][i2]

            if s1[i1] == s2[i2]:
                cache[i1][i2] =  1 + helper(s1, s2, i1+1, i2+1, cache)
            else:
                cache[i1][i2] = max(helper(s1, s2, i1+1, i2, cache), helper(s1, s2, i1, i2+1, cache)) 
            return cache[i1][i2]


        return helper(text1, text2, 0, 0, cache)