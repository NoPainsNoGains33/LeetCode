"""
# Definition for a Node.
class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self.parent = None
"""

class Solution:
    def lowestCommonAncestor(self, p: 'Node', q: 'Node') -> 'Node':
        ancestors = self.findAllAncestorsForANode(p)
        common_ancestor = self.findLowestCommonAncestor(ancestors, q)
        
        return common_ancestor
    
    def findAllAncestorsForANode(self, node):
        ancestors = set()
        
        while node:
            ancestors.add(node)
            node = node.parent
            
        return ancestors
    
    def findLowestCommonAncestor(self, ancestors, node):
        while node not in ancestors:
            node = node.parent
            
        return node
        
        
