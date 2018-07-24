// Problem from: https://leetcode.com/problems/factorial-trailing-zeroes/description/

/* 
 * Description:
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Example 1:
   Input: 3
   Output: 0
   Explanation: 3!=6, no trailing zero.
 * 
 * Example 2:
   Input: 5
   Output: 1
   Explanation: 5!=120, one trailing zero.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */

// Detailed explanation: http://www.purplemath.com/modules/factzero.htm

// MAIN IDEA: Find out how many multiples of 5 there are between 1 and n.

class solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for (long long i = 5; n/i > 0; i *= 5) {
            count += n / i;
        }
        return count;
    }
}