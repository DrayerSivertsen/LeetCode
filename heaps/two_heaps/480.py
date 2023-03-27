"""
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
"""


import heapq
class Heap:
    def __init__(self):
        self.small, self.large = [], []
    
    def addNum(self, num: int) -> None:
        # always add to maxheap and move to minheap as needed
        heapq.heappush(self.small, -1 * num)

        self.balance()

    def getMedian(self)-> int:
        if len(self.small) > len(self.large):
            return -1 * self.small[0]
        if len(self.large) > len(self.small):
            return self.large[0]
        return (-1 * self.small[0] + self.large[0]) / 2

    # remove number function
    def removeNum(self, num: int) -> None:
        median = self.getMedian()
        if num in self.large:
            self.large.remove(num)
        else:
            self.small.remove(-num)

        self.balance()

    def balance(self) -> None:
        # maxheap value greater than minheap val
        if (self.small and self.large and (self.small[0] * -1 > self.large[0])):
            val = -1 * heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        
        # handle uneven size
        if len(self.small) > len(self.large) + 1:
            val = -1 * heapq.heappop(self.small)
            heapq.heappush(self.large, val)
        if len(self.large) > len(self.small) + 1:
            val = heapq.heappop(self.large)
            heapq.heappush(self.small, -1 * val)

        heapq.heapify(self.small) # turns list to heap
        heapq.heapify(self.large) # turns list to heap


class Solution:
    def medianSlidingWindow(self, nums: List[int], k: int) -> List[float]:
        heap = Heap()
        L, R = 0, 0
        res = []

        while R - L < k:
            heap.addNum(nums[R])
            R += 1

        while R < len(nums):
            # store the median
            val = heap.getMedian()
            res.append(val)

            # slide the window
            heap.removeNum(nums[L])
            L += 1
            heap.addNum(nums[R])
            R += 1

        # save median for final window
        val = heap.getMedian()
        res.append(val)

        return res

