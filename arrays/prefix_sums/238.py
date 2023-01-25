"""
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.
"""


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        answer = []

        # prefix 
        prefix = 1 # default 1 (nothing in before)
        for num in nums:
            answer.append(prefix) # save prefix value in place
            prefix *= num

        # postfix
        postfix = 1 # default 1 (nothing in after)
        for i,num in reversed(list(enumerate(nums))):
            answer[i] *= postfix # multiply pre and post
            postfix *= num

        return answer
        