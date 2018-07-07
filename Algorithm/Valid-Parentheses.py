# Problem from: https://leetcode.com/problems/valid-parentheses/description/

"""
Valid Parentheses
Description: Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
    1. Open brackets must be closed by the same type of brackets.
    2. Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:
Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{()}"
Output: true
"""

class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        # If the length of s is 0, then return True
        if len(s) == 0:
            return True

        # If the length of s is 1, then it's impossible to have valid parentheses
        if len(s) == 1:
            return False

        parenthesesDict = {')':'(', ']':'[', '}':'{'}
        stack = []
        for i in s:
            # If i is an open bracket, then add to stack
            if i in parenthesesDict:
                stack.append(i)
            else:
                # If stack is empty or i is not the correct type of close bracket
                if not stack or parenthesesDict[i] != stack[-1]:
                    return False
                # Otherwise, delete the last character from stack 
                else:
                    stack.pop()

        return not stack

