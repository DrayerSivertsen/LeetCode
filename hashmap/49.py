"""
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
"""

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagramMap = defaultdict(list)

        for s in strs:
            counts = [0] * 26 # a ... z

            for c in s:
                counts[ord(c) - ord('a') - 1] += 1

            anagramMap[tuple(counts)].append(s)

        return anagramMap.values()

        
                