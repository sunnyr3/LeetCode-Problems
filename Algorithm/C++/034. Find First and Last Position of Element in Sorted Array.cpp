/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        
        int leftIndex = extremeInsertionIndex(nums, target, true);
        
        if (leftIndex == nums.size() || nums[leftIndex] != target)
            return ret;
        
        ret[0] = leftIndex;
        ret[1] = extremeInsertionIndex(nums, target, false) - 1;
        
        return ret;
    }

private:
    // Return the leftmost (or rightmost) index at which the target should be
    // inserted in sorted array "nums" via binary search
    int extremeInsertionIndex(vector<int> nums, int target, bool isleft) {
        int lo = 0, hi = nums.size();
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > target || (isleft && target == nums[mid])) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};