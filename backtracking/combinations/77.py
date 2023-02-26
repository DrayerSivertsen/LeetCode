"""
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
"""


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def helper(start: int, comb: List[int]):
            if len(comb) == k: # combination of length k
                res.append(comb.copy())
                return
            
            for i in range(start, n + 1):
                comb.append(i)
                helper(i + 1, comb) # one less value to loop through every call
                comb.pop()
        
        helper(1, [])
        return res