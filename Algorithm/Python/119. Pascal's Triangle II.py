# Problem from: https://leetcode.com/problems/pascals-triangle-ii/description/

'''
Given a non-negative index k where k <= 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

Example:
Input: 3
Output: [1,3,3,1]

Follow up: Could you optimize your algorithm to use only O(k) extra space?
'''

class Solution:
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        if rowIndex == 0:
            return [1]
        
        if rowIndex == 1:
            return [1,1]
        
        ret = [0] * (rowIndex+1)
        ret[0] = ret[rowIndex] = 1
        prev = []
        if rowIndex > 1:
            prev = self.getRow(rowIndex - 1)
            for i in range(1, rowIndex):
                ret[i] = prev[i-1] + prev[i]
        return ret