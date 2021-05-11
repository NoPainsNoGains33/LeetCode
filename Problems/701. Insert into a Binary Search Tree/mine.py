# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        if not root:
            return TreeNode(val)
        
        current = root
        prev = None
        while (current):
            prev = current
            if val < current.val:
                current = current.left
                if not current:
                    prev.left = TreeNode(val)
                    break
            else:
                current = current.right
                if not current:
                    prev.right = TreeNode(val)
                    break
        
        return root
