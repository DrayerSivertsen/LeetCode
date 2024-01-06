"""
Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.
"""

class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        st1, st2 = Counter(ransomNote), Counter(magazine)
        if st1 & st2 == st1:
            return True
        return False



# my solution
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # create lookup hashmap
        lookup = {}
        for c in magazine:
            if c in lookup:
                lookup[c] += 1
            else:
                lookup[c] = 1

        for c in ransomNote:
            if c in lookup and lookup[c] > 0:
                lookup[c] -= 1
            else:
                return False
            
        return True