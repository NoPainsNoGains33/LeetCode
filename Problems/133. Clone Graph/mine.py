"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

# 注意self啊！！写python函数的时候

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        

        all_nodes = self.visitGraph(node)
        node_mapping = self.copyNodes(all_nodes)
        self.copyEdges(all_nodes, node_mapping)
        
        return node_mapping[node]
    
    def visitGraph(self, node):
        queue = collections.deque([node])
        visited = set([node])
        
        while queue:
            current_node = queue.popleft()
            for neighbor in current_node.neighbors:
                if neighbor in visited:
                    continue
                visited.add(neighbor)
                queue.append(neighbor)
        
        return list(visited)
    
    def copyNodes(self, all_nodes):
        node_mapping = {}
        for node in all_nodes:
            node_mapping[node] = Node(node.val)
            
        return node_mapping
    
    def copyEdges(self, all_nodes, node_mapping):
        for node in all_nodes:
            new_node = node_mapping[node]
            for neighbor in node.neighbors:
                new_neighbor = node_mapping[neighbor]
                new_node.neighbors.append(new_neighbor)
        
