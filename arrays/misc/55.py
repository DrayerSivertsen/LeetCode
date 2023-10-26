"""

"""



class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = len(nums) - 1
        
        for i in range(len(nums) - 1, -1, -1):
            if i + nums[target] >= target:
                target = i

        return 1 if target == 0 else 0
