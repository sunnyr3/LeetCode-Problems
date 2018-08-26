# Problem from: https://leetcode.com/problems/longest-harmonious-subsequence/description/

'''
We define a harmonious array is an array where the difference between its maximum value and its value is EXACTLY 1.
Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.

Example 1:
Input: [1,3,2,2,5,2,3,7]
Output: 5
Explanation: The longest harmonious subsequence is [3,2,2,2,3].

Note: The length of the input array will not exceed 20,000.
'''

class Solution:
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        cmap = collections.Counter(nums)
        res = 0
        for key in cmap:
            if key+1 in cmap:
                res = max(res, cmap[key] + cmap[key+1])
        return res
                