"""
The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.
"""


class Solution:
    store = {0:0,1:1,2:1} # dict to dynamically store

    def tribonacci(self, n: int) -> int:
        # fibonacci but three sequence value
        if n < 3:
            return self.store[n] # base case
        elif n in self.store:
            return self.store[n] # dynamic case
        self.store[n] = self.tribonacci(n-3) + self.tribonacci(n-2) + self.tribonacci(n-1) # save new value
        return self.store[n]