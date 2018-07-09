# Problem from: https://leetcode.com/problems/majority-element/description/

"""
Majority Element

Given an array of size n, find the majority element. The majority element is the element that appears MORE THAN ceil(n/2) times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:
Input: [3,2,3]
Output: 3

Example 2:
Input: [2,2,1,1,1,2,2]
Output: 2
"""

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # If the elements are sorted in monotonically increasing order, the majority element can
        # be found at index (n/2) (and (n/2 + 1) if n is even).
        nums.sort()
        return nums[len(nums) // 2]