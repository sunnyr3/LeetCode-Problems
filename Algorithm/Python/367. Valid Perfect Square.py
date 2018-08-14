# Problem from: https://leetcode.com/problems/valid-perfect-square/description/

'''
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: DO NOT use any built-in library function such as sqrt().

Example 1:
Input: 16
Returns: True

Example 2:
Input: 14
Returns: False
'''

class Solution:
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        n = num
        while n*n > num:
            n = (n + num/n) // 2
        
        return n*n == num