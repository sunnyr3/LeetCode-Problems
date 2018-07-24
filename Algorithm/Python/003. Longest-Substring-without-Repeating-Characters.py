# Problem from: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/

"""
Longest Substring without Repeating Characters
Description: Given a string, find the length of the LONGEST SUBSTRING without repeating characters.

Examples:
1. Given "abcabcbb", the answer is "abc", which the length is 3.
2. Given "bbbbb", the answer is "b", which the length is 1.
3. Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a SUBSTRING.
"""

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        
        longest_len = 0
        currentString = []
        for x in s:
            if x in currentString:
                index = s.index(x)
                currentString = currentString[index+1:]
            
            currentString.append(x)

            if longest_len < len(currentString):
                longest_len = len(currentString)
        
        return longest_len