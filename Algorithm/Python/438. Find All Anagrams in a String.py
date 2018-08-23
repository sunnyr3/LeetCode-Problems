# Problem from: https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

'''
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:
Input: s: "cbaebabacd" p: "abc"
Output: [0, 6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s: "abab" p: "ab"
Output: [0, 1, 2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
'''

class Solution:
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        ret = []
        l = len(p)
        pcounter = collections.Counter(p)
        scounter = collections.Counter(s[:l-1])
        
        for i in range(l-1, len(s)):
            scounter[s[i]] += 1
            if scounter == pcounter:
                ret.append(i-l+1)
            scounter[s[i-l+1]] -= 1
            if scounter[s[i-l+1]] == 0:
                del scounter[s[i-l+1]]
        return ret