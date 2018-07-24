# Problem from: https://leetcode.com/problems/reverse-integer/description/

"""
Reverse Integer
Description: Given a 32-bit signed integer, reverse digits of an integer.

Example 1:
Input: 123
Output: 321

Example 2:
Input: -123
Output: -321

Example 3:
Input: 120
Output: 21

Note: Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range. For 
      the purpose of the problem, assume that your function returns 0 when the reversed integer overflows.
"""

class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        isNegative = False
        # If the integer is negative, then change it to be positive
        if x < 0:
            isNegative = True
            x = -x
        reverseX = 0
        while x > 0:
            # Get the remainder which is the last number of the integer
            remainder = x % 10
            # Then add the remainder to reverseX
            reverseX = reverseX*10 + remainder
            x = x // 10

        # If the reversed integer is outside of the 32-bit signed integer range, then return 0
        if reverseX >= (2**31 - 1):
            return 0

        if isNegative:
            return -reverseX
        
        return reverseX
