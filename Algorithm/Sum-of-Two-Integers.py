# Problem from: https://leetcode.com/problems/sum-of-two-integers/description/

"""
Description:
Calculate the sum of two integers a and b, but you are NOT ALLOWED to use the operator + and -.

Example:
Given a=1 and b=2, return 3.
"""

class Solution:
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        # 32 bits integer max
        MAX = 0x7FFFFFFF
        # 32 bits interger min
        MIN = 0x80000000
        # mask to get last 32 bits
        mask = 0xFFFFFFFF
        
        while b is not 0:
            a, b = (a ^ b) & mask, ((a & b) << 1) & mask
        
        if a <= MAX:
            return a
        else:
            return ~(a ^ mask)