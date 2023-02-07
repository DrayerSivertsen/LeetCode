"""
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def pairSum(self, head: Optional[ListNode]) -> int:
        slow, fast = head, head
        maxVal = 0

        # find middle of list
        while fast and fast.next:
            fast = fast.next.next
            slow = slow.next

        # reverse from middle on
        prev = None
        next = slow.next
        while next:
            slow.next = prev
            prev = slow
            slow = next
            next = next.next
        
        # reverse last pointer
        slow.next = prev

        # calculate max twin
        while slow:
            print(head.val + slow.val)
            maxVal = max(maxVal, head.val + slow.val)
            slow = slow.next
            head = head.next
        
        return maxVal
