"""
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
"""


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        # dictionary of keypad
        keypad = {'2':'abc', '3':'def', '4':'ghi', '5':'jkl', '6':'mno', '7':'pqrs', \
        '8':'tuv', '9':'wxyz'}

        res = []

        def dfs(i, subset):
            if len(subset) == len(digits):
                res.append(subset)
                return

            for c in keypad[digits[i]]:
                dfs(i+1, subset + c)

        if digits:
            dfs(0, '')
        return res
