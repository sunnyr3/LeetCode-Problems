// Problem is from: https://leetcode.com/problems/binary-tree-postorder-traversal/description/

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
    
private:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root)
            return;
        
        postorder(root->left, nodes);
        postorder(root->right, nodes);
        nodes.push_back(root->val);
    }
};