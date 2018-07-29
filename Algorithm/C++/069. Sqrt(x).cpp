/* Problem from: https://leetcode.com/problems/sqrtx/description/

Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:
Input: 4
Output: 2

Example 2:
Input: 8
Output: 2
*/

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;

        int res = x / 2;
        while (x/res < res || x/(res+1) >= res+1)
            res = (res + x/res) / 2;
        
        return res;
    }
};