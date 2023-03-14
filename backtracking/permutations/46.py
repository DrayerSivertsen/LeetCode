"""
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.
"""


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # O(n^2 * n!)
        def helper(i, nums):   
            if i == len(nums):
                return [[]]
            
            res = []
            perms = helper(i + 1, nums)
            for p in perms:
                for j in range(len(p) + 1):
                    pCopy = p.copy()
                    pCopy.insert(j, nums[i])
                    res.append(pCopy)
            return res

        return helper(0, nums)
        