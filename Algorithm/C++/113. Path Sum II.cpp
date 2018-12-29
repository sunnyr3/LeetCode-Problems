/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:
[
   [5,4,11,2],
   [5,8,4,5]
]
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        if (root) {
            vector<int> temp;
            helper(sum, result, temp, root, 0);
        }
        
        return result;
    }
    
private:
    void helper(int sum, vector<vector<int> > &result, vector<int> temp, TreeNode *node, int currsum) {
        temp.push_back(node->val);
        if (!node->right && !node->left) {
            if (currsum+node->val == sum) {
                result.push_back(temp);
            }
        }
        
        if (node->left) 
            helper(sum, result, temp, node->left, currsum+node->val);
        if (node->right) 
            helper(sum, result, temp, node->right, currsum+node->val);
    }
};