"""
Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
"""


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []

        nums.sort()

        def dfs(i: int, subset: List[int]) -> None:
            if i == len(nums):
                res.append(subset.copy())
                return

            # subsets that include nums[i]
            subset.append(nums[i])
            dfs(i + 1, subset)
            subset.pop()

            # subsets that don't include nums[i]
            while i < len(nums)-1 and nums[i] == nums[i+1]:
                i += 1
            dfs(i + 1, subset)

        dfs(0, [])

        return res