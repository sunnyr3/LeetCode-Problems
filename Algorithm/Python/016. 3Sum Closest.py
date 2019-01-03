'''
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        result = 0
        mindiff = 999999
        
        for i in range(len(nums)-2):
            l = i+1
            r = len(nums) - 1
            while l < r:
                temp = nums[i]+nums[l]+nums[r]
                if abs(temp - target) < mindiff:
                    mindiff = abs(temp - target)
                    result = temp
                    
                if temp - target < 0:
                    l += 1
                elif temp - target > 0:
                    r -= 1
                else:
                    return target
                
        return result