# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def trimBST(self, root: TreeNode, low: int, high: int) -> TreeNode:
        return self.trim_with_root_returned(root, low, high)
    
    # Return the root of a trimmed BST
    def trim_with_root_returned(self, curr, low, high):
        if curr is None:
            return None
        
        if curr.val < low:
            return self.trim_with_root_returned(curr.right, low, high)
        elif curr.val > high:
            return self.trim_with_root_returned(curr.left, low, high)
        
        curr.left = self.trim_with_root_returned(curr.left, low, high)
        curr.right = self.trim_with_root_returned(curr.right, low, high)
        return curr
