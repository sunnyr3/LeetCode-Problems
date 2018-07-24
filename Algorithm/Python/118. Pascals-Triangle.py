# Problem from: https://leetcode.com/problems/pascals-triangle/description/

"""
Description:
Given a non-negative integer numRows, generate the first numRows of Pascel's triangle.

Example:
Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
"""

class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        # Base cases
        if numRows == 0:
            return []
        if numRows == 1:
            return [[1]]
        if numRows == 2:
            return [[1], [1,1]]
        
        ret = self.generate(numRows - 1)

        # Create a new row 
        newRow = [1] * numRows
        for i in range(1, numRows-1):
            newRows[i] = ret[-1][i-1] + ret[-1][i]
        
        ret.append(newRow)
        return ret