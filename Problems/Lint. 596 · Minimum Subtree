"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: the root of binary tree
    @return: the root of the minimum subtree
    """
    def findSubtree(self, root):
        # write your code here
        subtree_root, sum_of_tree, minimum = self.findMinimumSubtree(root)

        return subtree_root

    def findMinimumSubtree(self, root):
        if root is None:
            return None, 0, sys.maxsize
        
        left, sum_of_left, left_minimum = self.findMinimumSubtree(root.left)
        right, sum_of_right, right_minimum = self.findMinimumSubtree(root.right)

        sum_of_whole = sum_of_left + root.val + sum_of_right
        minimum = min(left_minimum, right_minimum, sum_of_whole)
        if left_minimum == minimum:
            return left, sum_of_whole, minimum
        if right_minimum == minimum:
            return right, sum_of_whole, minimum
        return root, sum_of_whole, minimum
