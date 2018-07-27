/* Problem from: https://leetcode.com/problems/add-binary/description/

Given two binary strings, return their sum (also a binary string).
The input strings are both NON-EMPTY and contains only characters 1 or 0.

Example 1:
Input: a="11", b="1"
Output: "100"

Example 2:
Input: a="1010", "1011"
Output: "10101"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ret = "";
        int indexa = a.size()-1, indexb = b.size()-1;
        while (indexa>=0 || indexb>=0) {
            int numa = 0, numb = 0;
            if (indexa >= 0) numa = a[indexa] == '1';
            if (indexb >= 0) numb = b[indexb] == '1';
            
            ret = static_cast<char>(numa ^ numb ^ carry + '0') + ret;
            carry = numa + numb + carry >= 2;
            indexa--;
            indexb--;
        } 
        
        if (carry == 1) ret = '1' + ret;
        return ret;
    }
};