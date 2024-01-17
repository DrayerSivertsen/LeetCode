"""
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.
"""

class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        window = set()
        L = 0

        for R in range(len(nums)):
            if R - L > k:
                window.remove(nums[L])
                L += 1
            
            if nums[R] in window:
                return True
            window.add(nums[R])

        return False

# my solution
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        numMap = {}

        for i, n in enumerate(nums):
            if n in numMap:
                if i - numMap[n] <= k:
                    return True
                    
            numMap[n] = i

        return False