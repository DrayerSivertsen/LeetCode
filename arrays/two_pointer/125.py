"""
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = s.lower()
        print(len(s))

        for i in range(len(s)):
            print(i)
            if ord(s[i]) < 96 or ord(s[i]) > 122:
                s = s[:i] + s[(i+1):]
            print(s)
        s.replace(' ', '')
        print(s)
