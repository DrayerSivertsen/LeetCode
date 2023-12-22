"""
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray
 whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
"""

class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        l, curSum = 0, 0
        res = sys.maxsize
        
        for r in range(len(nums)):
            curSum += nums[r]

            while curSum >= target:
                res = min(res, (r - l) + 1)
                curSum -= nums[l]
                l += 1

        return res if res != sys.maxsize else 0


            