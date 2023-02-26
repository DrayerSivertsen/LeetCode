"""
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.
"""


class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        res = []

        def helper(i: int, comb: List[int]):
            if len(comb) == k: # combination length of k
                res.append(comb.copy())
                return
            
            if i > n: # always empty combination
                return
            
            comb.append(i)
            helper(i+1, comb) # dfs adding i
            comb.pop()

            helper(i+1, comb) # dfs not adding i
        
        helper(1, [])

        return res