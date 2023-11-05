"""

"""

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i, end = 0, len(nums) - 1
        limit = nums[i]

        # edge case: nums len of 1
        if len(nums) == 1:
            return True

        while i <= limit:
            if i + nums[i] >= end:
                return True

            limit = max(limit, i + nums[i])
            i += 1

        return False


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = len(nums) - 1
        
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[target] >= target:
                target = i

        return 1 if target == 0 else 0
