class Solution:
    def sequenceReconstruction(self, org: List[int], seqs: List[List[int]]) -> bool:
        if not seqs:
            return False
        # Build graph and in_degree
        n = len(org)
        graph = {}
        for seq in seqs:
            for node in seq:
                if node not in graph:
                    graph[node] = set()
        
        in_degree = {node : 0 for node in graph}
        for seq in seqs:
            for i in range(1, len(seq)):
                if seq[i] in graph[seq[i - 1]]:
                    continue
                graph[seq[i - 1]].add(seq[i])
                in_degree[seq[i]] += 1
                
        # Build the queue
        queue = collections.deque()
        for node, degree in in_degree.items():
            if degree == 0:
                queue.append(node)
        
        print(graph)
        print(in_degree)

        # Topological sort
        order = []
        while queue:
            if len(queue) > 1:
                return False
            current = queue.popleft()
            order.append(current)
            for neighbor in graph[current]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
        
        print(order)
        # Double check our result and org
        return len(graph) == len(org) and org == order
