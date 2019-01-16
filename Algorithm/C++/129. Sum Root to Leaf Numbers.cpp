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
    int sum;
    
    void dfs(TreeNode* node, int currsum) {
        currsum = currsum*10 + node->val;
        
        if (!node->left && !node->right) {
            sum += currsum;
        }
        
        if (node->left) {
            dfs(node->left, currsum);
        }
        if (node->right) {
            dfs(node->right, currsum);
        }
    }
    
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        
        sum = 0;
        dfs(root, 0);
        
        return sum;
    }
};