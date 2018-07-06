# Problem from: https://leetcode.com/problems/two-sum/description/

"""
Two Sum
Description: Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution, and you may not use that same element twice.

Example:
Given nums = [2, 7, 11, 15], target = 9, return [0, 1].
"""

class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtypr: List[int]
        """
        # Create a dictionary to store each integer and their indeces
        dict = {}
        for i in range(len(nums)):
            x = nums[i]
            if target - x in dict:
                return (dict[target - x], i)
            dict[x] = i