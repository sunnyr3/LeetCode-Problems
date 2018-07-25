# Problem from:  https://leetcode.com/problems/count-primes/description/

"""
Description:
Count the number of prime numbers less than a non-negative number, n.

Example:
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
"""

# Algorithm: Sieve of Eratosthenes

class Solution:
    def countPrime(self, n):
        """
        :type n: int
        :rtype: int
        """
        p = [True] * n
        p[0] = p[1] = False

        for i in range(int(n ** 0.5) + 1):
            if p[i] == True:
                j = i
                while j <= n:
                    j *= i
                    p[j] = False
        return sum(p)
        