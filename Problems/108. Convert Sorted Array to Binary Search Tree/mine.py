# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# Space complexity:
# O(N) for the node, O(logN) for recursion stack
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        root = self.buildBST(nums, 0, len(nums) - 1)
        
        return root
    
    def buildBST(self, nums, left, right):
        if left > right:
            return None
        if left == right:
            return TreeNode(nums[left])
        
        middle = (left + right) // 2
        left_node = self.buildBST(nums, left, middle - 1)
        right_node = self.buildBST(nums, middle + 1, right)
        
        return TreeNode(nums[middle], left_node, right_node)
