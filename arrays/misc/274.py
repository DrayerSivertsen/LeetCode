"""
Given an array of integers citations where citations[i] is the number of citations a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia: The h-index is defined as the maximum value of h such that the given researcher has published at least h papers that have each been cited at least h times.
"""

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        freq = {}
        res = 0

        for i in range(len(citations)):
            for j in range(res, citations[i] + 1):
                freq[j] = (freq[j] + 1) if j in freq else 1

                if freq[j] == j:
                    res = j

        return res

"""
The nuance here is that we realise that by sorting the array, we only need to visit each index of 
citations once and check if it satisfies, once it does, the rest do not need to be visited as they 
automatically satisfy the condition since the array is sorted.
"""

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        length = len(citations)
        citations.sort()
        for i in range(length):
            if citations[i] >= length - i:
                return length - i
        return 0