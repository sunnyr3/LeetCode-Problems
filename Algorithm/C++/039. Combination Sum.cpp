// Problem from: https://leetcode.com/problems/combination-sum/description/

/*
Given a set of candidate numbers (candidates) (without duplicates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note: 
1. All numbers (include target) will be positive integers.
2. The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
    [7],
    [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
    [2,2,2,2],
    [2,3,3],
    [3,5]
]
*/

class Solution {
public:
    void search(vector<int>& candidates, int index, vector<int>& temp, int target, vector<vector<int>>& result) {
         if (target == 0) {
             result.push_back(temp);
             return;
         }

         if (index == candidates.size() || target - candidates[index] < 0)
            return;

        temp.push_back(candidates[index]);
        search(candidates, index, temp, target - candidates[index], result);
        temp.pop_back();

        search(candidates, index+1, temp, target, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        search(candidates, 0, temp, target, result);

        return result;
    }
}