// Problem from: https://leetcode.com/problems/count-primes/description/

/* 
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 *
 * Example:
   Input: 10
   Output: 4
   Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
 */

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < int(sqrt(n))+1; i++) {
            if (isPrime[i]) {
                for (int j = i*i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < isPrime.size(); i++) {
            if (isPrime[i]) count++;
        }
        return count;
    }
}