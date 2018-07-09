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

        slow = head.next
        fast = head.next.next
        while slow is not fast:
            if fast == None or fast.next == None:
                return False
            slow = slow.next
            fast = fast.next.next
            
        return True