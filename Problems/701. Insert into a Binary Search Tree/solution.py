# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def insertIntoBST(self, root: TreeNode, val: int) -> TreeNode:
        current = root
        while(current):
            if val > current.val:
                if not current.right:
                    current.right = TreeNode(val)
                    return root
                else:
                    current = current.right
            else:
                if not current.left:
                    current.left = TreeNode(val)
                    return root
                else:
                    current = current.left
        
        return TreeNode(val)
