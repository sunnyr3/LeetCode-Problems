# Problem from: https://leetcode.com/problems/rotate-list/description/

'''
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

Example 2:
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getLength(self, head):
        cur = head
        length = 0
        while cur:
            cur = cur.next
            length += 1
        return length
    
    def rotateList(self, head, k, length):
        index = 1
        newNull = head
        newHead = head.next
        while index < length - k:
            newNull = newNull.next
            newHead = newHead.next
            index += 1
            
        newNull.next = None
        curr = newHead
        
        while curr.next:
            curr = curr.next
            
        curr.next = head
        
        return newHead
    
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return None
        length = self.getLength(head)
        toRotate = k % length
        if toRotate == 0:
            return head
        return self.rotateList(head, toRotate, length)