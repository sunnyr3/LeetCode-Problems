/*
A robot is located at the top-left corner of a m x n grid.

The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid.

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Note: m and n will be at most 100.

Example 1:
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& path) {
        int r = path.size(), c = path[0].size();
        
        if (path[0][0] == 1) return 0;
        
        path[0][0] = 1;
        
        // Fill the values of the first column
        for (unsigned int i = 1; i < r; i++) {
            if (path[i][0] == 0 && path[i-1][0] == 1) {
                path[i][0] = 1;
            }
            else {
                path[i][0] = 0;
            }
        }
        
        // Fill the values of the first row
        for (unsigned int i = 1; i < c; i++) {
            if (path[0][i] == 0 && path[0][i-1] == 1) {
                path[0][i] = 1;
            }
            else {
                path[0][i] = 0;
            }
        }
        
        for (unsigned int i = 1; i < r; i++) {
            for (unsigned int j = 1; j < c; j++) {
                if (path[i][j] == 0) {
                    path[i][j] = path[i-1][j] + path[i][j-1];
                }
                else {
                    path[i][j] = 0;
                }
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        
        return path[r-1][c-1];
    }
};