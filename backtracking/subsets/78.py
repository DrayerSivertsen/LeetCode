"""
Given an integer array nums of unique elements, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.
"""


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        subset = []
        
        # calculate tree of subsets
        def dfs (i: int):
            if i >= len(nums):
                res.append(subset.copy())
                return
                
            # decision tree include nums[i]
            subset.append(nums[i])
            dfs(i + 1)
            
            # decision tree NOT include nums[i]
            subset.pop()
            dfs(i + 1)
        

        dfs(0)
        return res