# Problem from: https://leetcode.com/problems/first-unique-character-in-a-string/description/

"""
Description:
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.

Note: You may assume the string only contains lowercase letters.
"""

class Solution:
    def firstUniqueChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        letters = 'abcdefghijklmnopqrstuvwxyz'
        index = [s.index(c) for c in letters if s.count(c) == 1]
        return min(index) if len(s) > 0 else -1