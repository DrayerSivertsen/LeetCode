"""
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.
"""


class Solution:
    def maxArea(self, height: List[int]) -> int:
        L, curArea, res = 0, 0, 0
        R = len(height)-1

        while L < R:
            curArea = min(height[L], height[R]) * (R-L) # calc area
            res = max(res, curArea) # save max

            if (height[L] < height[R]): # move pointer with lower height
                L += 1
            else:
                R -= 1
            
        return res