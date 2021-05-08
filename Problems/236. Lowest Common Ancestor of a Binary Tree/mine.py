# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        lowest_common_ancestor = self.findlowestCommonAncestor(root, p, q)
        
        return lowest_common_ancestor
    
    def findlowestCommonAncestor(self, current, p, q):
        if not current:
            return None
        
        if current == p or current == q:
            return current
        
        left = self.findlowestCommonAncestor(current.left, p, q)
        right = self.findlowestCommonAncestor(current.right, p, q)
        
        if left and right:
            return current
        
        if left and not right:
            return left
        
        if not left and right:
            return right
        
        return None
