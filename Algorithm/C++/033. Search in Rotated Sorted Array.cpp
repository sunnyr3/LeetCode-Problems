/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.
You may assume no duplicate exists in the array.
Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0, hi = nums.size()-1, mid;
        
        while (lo < hi) {
            mid = lo + (hi - lo) / 2;
            
            if ((target < nums[0]) == (nums[mid] < nums[0])) {
                if (nums[mid] < target)
                    lo = mid + 1;
                else if (nums[mid] > target)
                    hi = mid;
                else 
                    return mid;
            }
            // target is on the right side
            else if (target < nums[0])
                lo = mid + 1;
            // target is on the left side
            else 
                hi = mid;
        }
        
        return -1;
    }
};