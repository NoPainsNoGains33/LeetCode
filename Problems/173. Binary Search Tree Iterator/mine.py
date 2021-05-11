# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.sorted_nodes = []
        
        self._inorderTraversal(root)
        self.index = -1

    def _inorderTraversal(self, root):
        if not root:
            return
        self._inorderTraversal(root.left)
        self.sorted_nodes.append(root.val)
        self._inorderTraversal(root.right)

    def next(self) -> int:
        self.index += 1
        return self.sorted_nodes[self.index]
        

    def hasNext(self) -> bool:
        if self.index < len(self.sorted_nodes) - 1:
            return True
        return False


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
