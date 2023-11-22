"""
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
"""


class Solution:
    def intToRoman(self, num: int) -> str:
        # Creating Dictionary for Lookup
        key = {'I': 1, 'IV': 4, 'V': 5, 'IX': 9, 'X': 10, 'XL': 40, 'L': 50, 'XC': 90, 
               'C': 100, 'CD': 400, 'D': 500, 'CM': 900, 'M': 1000}

        res = ""

        for sym, val in reversed(key.items()):
            if num // val:
                count = num // val
                res += (sym * count)
                num = num % val

        return res
