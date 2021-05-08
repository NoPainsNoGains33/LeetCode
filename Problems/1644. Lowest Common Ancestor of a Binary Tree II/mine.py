# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        lowest_common_ancestor, p_exist, q_exist = self.findLowestCommonAncestor(
            root, p, q
        )
        
        if p_exist and q_exist:
            return lowest_common_ancestor
        
        return None
    
    def findLowestCommonAncestor(self, root, p, q):
        if root == None:
            return None, False, False
            
        left, left_p_exist, left_q_exist = self.findLowestCommonAncestor(root.left, p, q)
        right, right_p_exist, right_q_exist = self.findLowestCommonAncestor(root.right, p, q)

        if left and right:
            return root, True, True
        if left:
            if root == p or root == q:
                return root, True, True
            return left, left_p_exist, left_q_exist
        if right:
            if root == p or root == q:
                return root, True, True
            return right, right_p_exist, right_q_exist
        if root == p:
            return root, True, False
        if root == q:
            return root, False, True
        return None, False, False
