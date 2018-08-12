# Problem from: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

'''
Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:
1. You returned answers (both index1 and index2) are not zero-based.
2. You may assume that each input would have exactly one solution and you may not use the same element twice.

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
'''

class Solution:
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        index1 = 0
        index2 = len(numbers) - 1
        
        while index1 < index2:
            if numbers[index1] + numbers[index2] == target:
                return [index1+1, index2+1]
            if numbers[index1] + numbers[index2] < target:
                index1 += 1
            else:
                index2 -= 1
                
        return []