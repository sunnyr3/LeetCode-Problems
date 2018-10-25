// Problem is from: https://leetcode.com/problems/search-a-2d-matrix/description/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m*n - 1;

        while (start <= end) {
            int mid = start + (end-start)/2;
            int temp = matrix[mid/n][mid%n];

            if (target < temp){
                end = mid - 1;
            }
            else if (target > temp)
                start = mid + 1;
            else 
                return true;
        }
        return false;
    }
}