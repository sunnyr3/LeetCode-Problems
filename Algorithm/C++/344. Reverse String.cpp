/* Problem from: https://leetcode.com/problems/reverse-string/description/

Write a function that takes a string as input and returns the string reversed.

Example:
Given s="hello", return "olleh".
*/

class Solution {
public:
    string reverseString(string s) {
        int left = 0, right = s.length() - 1;
        while (left < right) {
            swap(s[left++], s[right--]);
        }
        return s;
    }
};