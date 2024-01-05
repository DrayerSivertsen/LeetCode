"""
Given a string s, find the length of the longest 
substring
 without repeating characters.
"""

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        contains = set()
        l = 0
        res = 0

        for r in range(len(s)):
            while s[r] in contains:
                contains.remove(s[l])
                l += 1

            contains.add(s[r])
            res = max(res, r - l + 1)

        return res




# my solution
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res, curr = 0, 0
        contains = set()

        l, r = 0, 0

        while r < len(s):
            if s[r] not in contains:
                curr += 1
                contains.add(s[r])
                r += 1
            else:
                curr -= 1
                contains.remove(s[l])
                l += 1
            
            res = max(res, curr)
        
        return res