# Problem from: https://leetcode.com/problems/longest-common-prefix/description/

"""
Longest Common Prefix
Description: Write a function to find the longest common prefix string amongst an array of strings.
             If there is no common prefix, return an empty string ""

Example 1:
Input: ["flower", "flow", "flight"]
Output: "fl"

Example 2:
Input: ["dog", "racecar", "car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Note: All given inputs are in lowercase letters a-z.
"""

class Solution:
    def isCommonPrefix(self, strs, length):
        """
        :type strs: List[str]
        :type len: int
        :rtype: bool
        """
        # Get the temporary common prefix 
        tempPrefix = strs[0][:length]
        for i in range(1, len(strs)):
            # If any string does not have the same prefix, then return False
            if strs[i][:length] != tempPrefix:
                return False
        #Otherwise, return True
        return True

    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        # If the size of the string array is 0, then return null
        if len(strs) == 0:
            return ""
        # Get the length of the shortest string
        shortestLen = 0
        for i in range(len(strs)-1):
            shortestLen = min(len(strs[i]), len(strs[i+1]))

        low = 1
        high = shortestLen
        while low <= high:
            middle = int((low + high) / 2)
            if self.isCommonPrefix(strs, middle):
                low = middle + 1
            else:
                high = middle - 1
        
        end = int((low + high) / 2)
        return strs[0][:end]