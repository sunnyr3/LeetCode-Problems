# Problem from: https://leetcode.com/problems/move-zeroes/description/

"""
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:
Input: [0,1,0,3,12]
Output: [1,3,12,0,0]

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
"""
class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        lastNonZeroIndex = 0
        for cur in range(len(nums)):
            if nums[cur] != 0:
                nums[cur], nums[lastNonZeroIndex] = nums[lastNonZeroIndex], nums[cur]
                lastNonZeroIndex += 1