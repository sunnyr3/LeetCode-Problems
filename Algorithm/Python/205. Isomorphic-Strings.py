# Problem from: https://leetcode.com/problems/isomorphic-strings/description/

"""
Isomorphic Strings:
Description: Given two strings s and t, determine if they are isomorphic.
             Two strings are isomorphic if the characters in s can be replaced to get t.
             All occurrencies of a character must be replaced with another character while preserving the order of characters. No two characters may
             map to the same character but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: True

Example 2:
Input: s = "foo", t = "bar"
Output: False

Example 3:
Input: s = "paper", t = "title"
Output: True

Note: You may assume both s and t have the same length.
"""

class Solution:
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        MAX_CHARS = 256

        if len(s) != len(t):
            return False

        # To mark visited characters in t
        marked = [False] * MAX_CHARS

        # To store mapping of every character from s to that of t
        mapping = [-1] * MAX_CHARS

        for i in range(len(s)):
            # If current character of s is first time seen
            if mapping[ord(s[i])] == -1:
                
                # If current character of t is already seen, then return false
                if marked[ord(t[i])]:
                    return False
                
                # Mark current character of t as visited
                marked[ord(t[i])] = True

                # Store mapping of current character
                mapping[ord(s[i])] = t[i]

            # If current character is not first appearance in s, 
            # then check if previous appearance mapped to same character of t
            if mapping[ord(s[i])] != t[i]:
                return False

        return True
