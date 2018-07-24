# Problem from: https://leetcode.com/problems/climbing-stairs/description/

"""
Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:
Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
"""

# Similar to solve for fibonacci numbers

class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        # Base cases
        if n <= 0:
            return 0
        if n == 1:
            return 1
        if n == 2:
            return 2

        one_step_before = 2
        two_steps_before = 1
        solution = 0

        for i in range(2, n):
            solution = one_step_before + two_steps_before
            two_steps_before = one_step_before
            one_step_before = solution
        
        return solution