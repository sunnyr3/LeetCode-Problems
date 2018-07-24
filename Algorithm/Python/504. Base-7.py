# Problem from: https://leetcode.com/problems/base-7/description/

"""
Base 7
Description: Given an integer, return its base 7 string representation.

Example 1: 
Input: 100
Output: "202"

Example 2:
Input: -7 
Output: "-10"

Note: The input will be in range of [-1e7, 1e7].
"""

class Solution:
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        # If the number is 0, then just return 0 as a string
        if num == 0:
            return '0'

        # If the number is negative, then convert it to be positive
        if num < 0:
            sign = '-'
            num = -num
        else:
            sign = ''
      
        ret = ''
        while num > 0:
            convertNum = int(num % 7)
            num = int(num / 7)
            ret = str(convertNum) + ret
        
        return sign + ret
