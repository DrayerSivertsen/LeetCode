"""
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.
"""


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        # O(n^2 * n!)
        perms = [[]]

        for n in nums:
            nextPerms = []
            for p in perms:
                for i in range(len(p) + 1):
                    pCopy = p.copy()
                    pCopy.insert(i, n)
                    if pCopy not in nextPerms:
                        nextPerms.append(pCopy)
                perms = nextPerms
        
        return perms
