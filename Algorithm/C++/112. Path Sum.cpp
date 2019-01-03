/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:
Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) 
            return false;
        
        queue<pair<TreeNode*, int> > q;
        q.push(make_pair(root, sum - root->val));
        
        while (!q.empty()) {
            pair<TreeNode*, int> current = q.front();
            TreeNode* node = current.first;
            int currsum = current.second;
            q.pop();
            
            if (currsum == 0 && !node->left && !node->right)
                return true;
            
            if (node->left){
                q.push(make_pair(node->left, currsum - node->left->val));
            }
            if (node->right) {
                q.push(make_pair(node->right, currsum - node->right->val));
            }
        }
        
        return false;
    }
};