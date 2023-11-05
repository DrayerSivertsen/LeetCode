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
        goal = len(nums) - 1

        for i in range(len(nums) - 1, -1, -1):
            if i + nums[i] >= goal:
                goal = i

        return True if goal == 0 else False
