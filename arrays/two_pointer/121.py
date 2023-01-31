"""
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
"""


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        L, R = 0, 1
        profit = 0

        while R < len(prices):
            if prices[R] < prices[L]: # update L to lowest val seen
                L = R

            profit = max(prices[R] - prices[L], profit) # calc profit
            R += 1

        return profit