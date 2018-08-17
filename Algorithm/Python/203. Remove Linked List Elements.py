# Problem from: https://leetcode.com/problems/remove-linked-list-elements/description/

'''
Remove all elements from a linked list of integers that have value val.

Example:
Input: 1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        if not head:
            return head
        
        ret = prev = ListNode(-1)
        prev.next = head
        curr = head
        while curr:
            if curr.val == val:
                prev.next = curr.next
            else:
                prev = prev.next
            curr = curr.next
        return ret.next