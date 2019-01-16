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
    int rob(TreeNode* root) {
        int l, r;
        return tryrob(root, l, r);
    }
    
private:
    int tryrob(TreeNode *node, int& l, int& r) {
        if (!node) return 0;
        
        int ll = 0, lr = 0, rr = 0, rl = 0;
        l = tryrob(node->left, ll, lr);
        r = tryrob(node->right, rl, rr);
        
        return max(node->val + ll + lr + rl + rr, r + l);
    }
};