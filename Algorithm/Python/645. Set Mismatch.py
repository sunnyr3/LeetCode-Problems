# Problem from: https://leetcode.com/problems/set-mismatch/description/

'''
The set s originally contains numbers from 1 to n. Bur unfortunately, due to the data error, one of the numbers in the set got dulplicated to 
ANOTHER number in the set, which results in repetition of one number and loss of another number.

Given an array nums representing the data status of the set after the error. Your task is to firstly find the number occurs twice and then find
the number that is missing. Return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]

Note:
1. The given array size will in the range [2, 10000].
2. The given array's number won't have any order.
'''

class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        l = len(nums)
        count = [0] * (l+1)
        for n in nums:
            count[n] += 1
        for i in range(1, l+1):
            if count[i] == 2:
                dup = i
            elif count[i] == 0:
                none = i
        
        return dup, none

        # Using math - faster
        L = len(nums)
        x = sum(nums) - L*(L+1)/2
        y = (sum(n*n for n in nums) - (L*(L+1)*(2*L+1))/6) / x
        return int((x+y) / 2), int((y-x) / 2)