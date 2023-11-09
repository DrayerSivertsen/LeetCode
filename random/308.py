"""
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
"""

class RandomizedSet:

    def __init__(self):
        self.data_map = {}
        self.data = []

    def insert(self, val: int) -> bool:
        if val in self.data_map:
            return False

        self.data_map[val] = len(self.data) # store the index
        self.data.append(val)

        return True

    def remove(self, val: int) -> bool:
        if val not in self.data_map:
            return False

        # set the last element to the location of val (will be removed)
        index_to_remove = self.data_map[val]
        last_element = self.data[-1]

        self.data_map[last_element] = index_to_remove
        self.data[index_to_remove] = last_element

        self.data.pop()
        self.data_map.pop(val)

        return True

    def getRandom(self) -> int:
        # leetcode automatically 'import random'
        return random.choice(self.data)

# My Attempt
class RandomizedSet:

    def __init__(self):
        self.nums = []

    def insert(self, val: int) -> bool:
        if val in self.nums:
            return False
        else:
            self.nums.append(val)
            return True

    def remove(self, val: int) -> bool:
        if val in self.nums:
            self.nums.remove(val)
            return True
        
        return False

    def getRandom(self) -> int:
        return self.nums[random.randint(0, len(self.nums)-1)]