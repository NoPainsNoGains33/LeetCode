"""
class DirectedGraphNode:
     def __init__(self, x):
         self.label = x
         self.neighbors = []
"""

class Solution:
    """
    @param graph: A list of Directed graph node
    @return: Any topological order for the given graph.
    """
    def topSort(self, graph):
        # write your code here
        node_to_indegree = self.getIndegree(graph)
        # start_nodes = [node for node in graph if node_to_indegree[node] == 0]
        # 这两种初始化都可以
        start_nodes = [node for node, indegree in node_to_indegree.items() if indegree == 0]
        queue = collections.deque(start_nodes)

        order = []
        while queue:
            current = queue.popleft()
            order.append(current)
            for neighbor in current.neighbors:
                node_to_indegree[neighbor] -= 1
                if node_to_indegree[neighbor] == 0:
                    queue.append(neighbor)

        return order

    def getIndegree(self, graph):
        node_to_indegree = {node : 0 for node in graph}
        for node in graph:
            for neighbor in node.neighbors:
                node_to_indegree[neighbor] += 1
        
        return node_to_indegree
