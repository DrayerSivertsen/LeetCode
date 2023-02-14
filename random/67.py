"""
Given two binary strings a and b, return their sum as a binary string.
"""


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ""
        carry = 0
        a, b = a[::-1], b[::-1] # reverse binary numbers

        for i in range(max(len(a), len(b))):
            digitA = ord(a[i]) - ord('0') if i < len(a) else 0 # convert to integer
            digitB = ord(b[i]) - ord('0') if i < len(b) else 0 # convert to integer

            total = digitA + digitB + carry

            char = str(total % 2) # binary digit
            res = char + res
            carry = total // 2 # save carry

        if carry: # carry is 1 so add extra digit
            res = '1' + res

        return res

