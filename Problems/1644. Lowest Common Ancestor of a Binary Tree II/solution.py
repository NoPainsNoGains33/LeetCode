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
        
        return lowest_common_ancestor if p_exist and q_exist else None
    
    def findLowestCommonAncestor(self, root, p, q):
        if root == None:
            return None, False, False
            
        left, left_p_exist, left_q_exist = self.findLowestCommonAncestor(root.left, p, q)
        right, right_p_exist, right_q_exist = self.findLowestCommonAncestor(root.right, p, q)
        
        p_exist = left_p_exist or right_p_exist or root == p
        q_exist = left_q_exist or right_q_exist or root == q

        if root == p or root == q:
            return root, p_exist, q_exist
        if left and right:
            return root, p_exist, q_exist
        if left:
            return left, p_exist, q_exist
        if right:
            return right, p_exist, q_exist
        return None, False, False
