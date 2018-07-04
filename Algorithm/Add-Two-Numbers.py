# Problem is from: https://leetcode.com/problems/add-two-numbers/description/

"""
Add Two Numbers
Description: You are given two NON-EMPTY linked lists representing two non-negative integers. The digits are stored in REVERSE ORDER and each 
             of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
"""

# Definition for singly-linked list:
# class ListNode:
#   def __init__(self, x):
#       self.val = x
#       self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        ret = ListNode(0)
        self = ret
        carry = 0

        while l1 or l2:
            if l1:
                ret.val += l1.val
                l1 = l1.next
            if l2:
                ret.val += l2.val
                l2 = l2.next
            ret.val += carry

            if ret.val >= 10:
                ret.val -= 10
                carry = 1
            else:
                carry = 0
            
            if l1 or l2:
                ret.next = ListNode(0)
                ret = ret.next
            
        if carry > 0:
            ret.next = ListNode(carry)
        
        return self