/*
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

Example:
Given array nums = [-1, 2, 1, -4], and target = 1.
The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result, mindiff = 9999;
        for (unsigned int i = 0; i < nums.size()-2; i++) {
            int l = i+1, r = nums.size()-1;
            while (l < r) {
                int temp = nums[i]+nums[l]+nums[r];
                if (abs(temp - target) < mindiff) {
                    mindiff = abs(temp - target);
                    result = temp;
                }
                if (temp - target > 0) r--;
                else if (temp - target < 0) l++;
                else return result;
            }
        }
        return result;
    }
};