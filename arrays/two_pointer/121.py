"""
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
"""


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        l, r = 0, 1
        res = 0

        while r < len(prices):
            if prices[r] < prices[l]:
                l = r # move L to new min
            else:
                profit = prices[r] - prices[l]
                res = max(res, profit) # calc max profit

            r += 1

        return res