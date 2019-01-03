/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
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
    int minDepth(TreeNode* root) {
        queue<pair<TreeNode*, int> > q;
        
        if (!root)
            return 0;
        else 
            q.push(make_pair(root, 1));
        
        int currdepth = 0;
        
        while (!q.empty()) {
            pair<TreeNode*, int> curr = q.front();
            TreeNode *node = curr.first;
            currdepth = curr.second;
            q.pop();
            
            if (!node->left && !node->right)
                break;
            
            if(node->left)
                q.push(make_pair(node->left, currdepth+1));
            if (node->right)
                q.push(make_pair(node->right, currdepth+1));
        }
        
        return currdepth;
    }
};