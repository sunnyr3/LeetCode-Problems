/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?
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
    // Morris algorithm
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        TreeNode *node = root;
        while (node) {
            if (!node->left) {
                nodes.push_back(node->val);
                node = node->right;
            }
            else {
                TreeNode *predecessor = node->left;
                while (predecessor->right && predecessor->right != node) {
                    predecessor = predecessor->right;
                }
                
                if (predecessor->right == node) {
                    predecessor->right = NULL;
                    node = node->right;
                }
                else {
                    nodes.push_back(node->val);
                    predecessor->right = node;
                    node = node->left;
                }
            }
        }
        
        return nodes;
    }
};