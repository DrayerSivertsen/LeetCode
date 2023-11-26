"""
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        res = ""

        for i in range(len(strs[0])):
            for s in strs:
                if i == len(s) or s[i] != strs[0][i]:
                    return res
            
            res += strs[0][i]


        return res
    

# My attempt
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        length = 10000
        res = ''
        for s in strs:
            length = min(length, len(s))

        for j in range(length):
            for i in range(len(strs)-1):
                if strs[i][j] == strs[i+1][j]:
                    continue
                else:
                    return res

            res += strs[0][j]

        return res