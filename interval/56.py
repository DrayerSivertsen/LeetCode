"""
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
"""


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda i : i[0])
        res = [intervals[0]]

        for start, end in intervals[1:]:
            lastEnd = res[-1][1]

            if start <= lastEnd:
                res[-1][1] = max(end, lastEnd)
            else:
                res.append([start, end])

        return res
