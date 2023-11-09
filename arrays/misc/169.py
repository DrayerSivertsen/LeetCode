"""
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
"""

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res, count = 0, 0

        for n in nums:
            if count == 0:
                res = n
            count += 1 if n == res else -1
            
        return res

# My attempt
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        freq = {}
        target = len(nums) / 2

        for n in nums:
            freq[n] = 1 + freq.get(n, 0)
            if freq[n] > target:
                return n
            

