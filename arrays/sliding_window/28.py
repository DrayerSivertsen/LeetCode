"""
Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
"""

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if needle == "":
            return 0

        for i in range(len(haystack) + 1 - len(needle)):
            if haystack[i:i + len(needle)] == needle:
                return i

        return -1


# My solution
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        l, r = 0, 0

        while r < len(haystack):
            while haystack[l:r] == needle[0:r-l]:
                r += 1
                if haystack[l:r] == needle:
                    return l
            l += 1

        return -1