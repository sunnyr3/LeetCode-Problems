# Problem from: https://leetcode.com/problems/linked-list-cycle/description/

""" 
Linked List Cycle

Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        if head == None or head.next == None:
            return False
        
        prev = head.next
        curr = head.next.next
        while curr is not None and curr.next is not None:
            if curr == prev:
                return True
            prev = prev.next
            curr = curr.next.next
        return False