# Problem from: https://leetcode.com/problems/palindrome-number/description/

"""
Palindrome Number
Description: Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:
Input: 121
Output: True

Example 2:
Input: -121
Output: False

Example 3:
Input: 10
Output: False

Follow up: Could you solve it without converting the integer to a string?
"""

class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        # If x is negative, then return False
        if x < 0:
            return False
        # If x is a product of 10 and it's not 0, then return False
        if x % 10 == 0 and x != 0:
            return False

        original = x
        reverse = 0
        while x > 0:
            remainder = x % 10
            reverse = reverse * 10 + remainder
            x = x // 10

        # If the reversed x is equal to the original one, then it's a palindrome number
        if reverse == original:
            return True
        # Otherwise, return False
        return False