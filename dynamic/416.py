"""
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
"""


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        if sum(nums) % 2:
            return False

        target = sum(nums) / 2

        dp = set()
        dp.add(0)

        for i in range(len(nums)):
            nextDP = set()
            for t in dp:
                nextDP.add(t + nums[i])
                nextDP.add(t)
            dp = nextDP
        return True if target in dp else False



# My attempt
class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        if sum(nums) % 2:
            return False

        target = sum(nums) / 2

        def dfsHelper(i, arr, nums):
            print(arr, nums)
            if target == sum(nums):
                return True

            if i >= len(nums):
                return False

            if dfsHelper(i+1, arr.copy(), nums.copy()):
                return True

            tmp = nums[i]
            nums[i] = 0
            arr.append(tmp)
             # append curr to arr


            return dfsHelper(i+1, arr.copy(), nums.copy())
            
        return dfsHelper(0, [], nums)


s = Solution()

print(s.canPartition([1,5,11,5]))
        

                

