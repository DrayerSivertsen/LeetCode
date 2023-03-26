"""
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.
"""


class Solution:
    def isPalindrome(self, s: str) -> bool:
        L, R = 0, len(s) - 1

        while L < R:
            while L < R and not self.alphaNum(s[L]): # move until alphaNum
                L += 1
            while R > L and not self.alphaNum(s[R]): # move until alphaNum
                R -= 1

            if s[L].lower() != s[R].lower(): # check palindrome
                return False
            L, R = L + 1, R - 1

        return True

    def alphaNum(self, c): # checks if char is letter or number
        return (ord('A') <= ord(c) <= ord('Z') or 
                ord('a') <= ord(c) <= ord('z') or 
                ord('0') <= ord(c) <= ord('9'))
