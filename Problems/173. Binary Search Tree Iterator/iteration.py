# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# For next, since get all next needs O(N), so every time it needs O(1)
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.stack = []
        self._inorder_left(root)
        
    def _inorder_left(self, root):
        while root:
            self.stack.append(root)
            root = root.left
    
    def next(self) -> int:
        top_of_stack = self.stack.pop()
        
        # If top element has right child, do the inorder left
        if top_of_stack.right:
            self._inorder_left(top_of_stack.right)
        
        return top_of_stack.val
        

    def hasNext(self) -> bool:
        return len(self.stack) > 0


# Your BSTIterator object will be instantiated and called as such:
# obj = BSTIterator(root)
# param_1 = obj.next()
# param_2 = obj.hasNext()
