"""
You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.
"""


class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        i, j = 0, 1

        if len(nums) == 1:
            return nums[0]

        while j < len(nums):
            if nums[i] != nums[j]:
                return nums[i]

            i += 2
            j += 2

        return nums[i] # single is last element