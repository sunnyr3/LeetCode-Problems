/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:
Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        vector<vector<int> > sum(r, vector<int>(c, 0));
        sum[0][0] = grid[0][0];
        for (unsigned int i = 1; i < r; i++) {
            sum[i][0] = sum[i-1][0] + grid[i][0];
        }
        
        for (unsigned int i = 1; i < c; i++) {
            sum[0][i] = sum[0][i-1] + grid[0][i];
        }
        
        for (unsigned int i = 1; i < r; i++) {
            for (unsigned int j = 1; j < c; j++) {
                sum[i][j] = min(sum[i-1][j], sum[i][j-1]) + grid[i][j];
            }
        }
        
        return sum[r-1][c-1];
    }
};