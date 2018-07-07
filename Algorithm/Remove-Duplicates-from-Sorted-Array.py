# Problem from: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

"""
Remove Duplicates from Sorted Array

Given a sorted array nums, remove the duplicates IN-PLACE such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by MODIFYING THE INPUT ARRAY IN-PLACE with O(1) extra memory.

Example 1:
Given nums = [1,1,2]
Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
It doesn't matter what you leave beyond the returned length.

Example 2:
Given nums = [0,0,1,1,1,2,2,3,3,4],
Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.
It doesn't matter what values are set beyond the returned length.

Clarification:
Confused why returned value is an integer but your answer is an array?
Note that the input array is passed in by REFERENCE, which means modification to the input array will be known to the callers as well.
"""

class Solution:
    def removeDuplicates(slef, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1]:
                count += 1
            else:
                nums[i-count] = nums[i]

        return len(nums) - count