/* Probleme from: https://leetcode.com/problems/intersection-of-two-arrays-ii/description/

Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1,2,2,1], nums2=[2,2], return [2,2].

Note:
1. Each element in the result should appear as many times as it shows in both arrays.
2. The result can be in any order.

Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
        
        vector<int> ret;
        unordered_map<int, int> temp;
        for (int num:nums1) temp[num]++;
        
        for (int num:nums2){
            if (temp.find(num) != temp.end() && temp[num] > 0){
                ret.push_back(num);
                temp[num]--;
            }
        }
        
        return ret;
    }
};