# Problem from: https://leetcode.com/problems/min-cost-climbing-stairs/description/

'''
On a staircase, the ith step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb or two steps. You need to find minimum cost to reach the top of the floor, and you can 
either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.

Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].

Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].
'''

class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """

        # Bottom up method
        result = [0] * (len(cost) + 1)

        if len(cost) == 1:
            return cost[0]
        if len(cost) == 2:
            return cost[1]
        
        result[1] = cost[0]
        result[2] = cost[1]

        for i in range(1, len(cost)+1):
            result[i] = min(result[i-2]+cost[i-1], result[i-1]+cost[i-1])
        
        return min(result[len(cost)-1], result[len(cost)])