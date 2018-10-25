// Problem is from: https://leetcode.com/problems/binary-tree-inorder-traversal/description/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }
    
private:
    void inorder(TreeNode* node, vector<int>& vec) {
        if (!node)
            return;
        
        inorder(node->left, vec);
        vec.push_back(node->val);
        inorder(node->right, vec);
    }
};