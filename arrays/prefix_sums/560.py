"""
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.
"""


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res = 0
        curSum = 0
        # hash map to store prefix sum counts
        prefixSums = {0 : 1} # initialize with 0 to count empty array

        for n in nums:
            curSum += n
            diff = curSum - k

            res += prefixSums.get(diff, 0) # add any diffs that result in k
            prefixSums[curSum] = 1 + prefixSums.get(curSum, 0) # update hash

        return res