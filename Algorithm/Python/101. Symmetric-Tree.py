# Problem from: https://leetcode.com/problems/symmetric-tree/description/

"""
Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie. symmetric around its center).

For example, this binary tree [1,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.
"""

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # Recursive solution
    def recursiveCheck(self, l, r):
        """
        :type l: TreeNode
        :type r: TreeNode
        :rtype: bool
        """
        if l or r:
            return l.val == r.val and self.recursiveCheck(l.left, r.right) and self.recursiveCheck(l.right, r.left)
        return l is r

    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        # Base case
        if root == None:
            return True

        return self.recursiveCheck(root.left, root.right)

    # Iterative solution
    def isSymmetric_iterative(self, root):
        # Base case
        if root == None:
            return True
        
        stack = [(root.left, root.right)]
        while stack:
            left, right = stack.pop()
            if left == None and right == None:
                continue
            if left == None or right == None:
                return False
            if left.val == right.val:
                stack.append((left.left, right.right))
                stack.append((left.right, right.left))
            else:
                return False
                
        return True