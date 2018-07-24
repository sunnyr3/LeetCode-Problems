# Problem from: https://leetcode.com/problems/longest-palindromic-substring/description/

"""
Longest Palindromic Substring
Description: Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2: 
Input: "cbbd"
Output: "bb"
"""

# An O(N) solution (Manacher's Algorithm)
# Detailed explaination: https://www.akalin.com/longest-palindrome-linear-time

# Algorithm method:
# 1. Initialize the lengths array to the number of possible centers
# 2. Set the current center to the first center
# 3. Loop while the current center is valid:
#   a. Expand to the left and right simultaneously until we find the largest palindrome around this center
#   b. Fill in the appropriate entry in the longest palindrome lengths array 
#   c. Iterate through the longest palindrome lengths array backwards and fill in the corresponding values to the right of the entry for the 
#      current center until an unknown value is encountered
#   d. Set the new center to the index of this unknown value
# 4. Return the lengths array

class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # If the length of s is one or zero, then just return the string s
        if len(s) == 1 or len(s) == 0:
            return s
        
        resultStr = ''
        for i in range(len(s)):
            left, right = i, i
            while (left > 0 and right < len(s) - 1 and s[left-1] == s[right+1]):
                left -= 1
                right += 1
            
            if (right - left + 1 > len(resultStr)):
                resultStr = s[left:right-left+1]
        
        for i in range(len(s) - 1):
            if (s[i] == s[i+1]):
                left = i
                right = i+1

                while (left > 0 and right < len(s) - 1 and s[left-1] == s[right+1]):
                    left -= 1
                    right += 1
            
                if (right - left + 1 > len(resultStr)):
                    resultStr = s[left:right-left+1]   
        return resultStr