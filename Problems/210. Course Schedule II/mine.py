# For space complexity, we use two arrays:
# One is for order: O(N)
# One is for neighbours: O(M)
# So it is O(N + M)
class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:        
        graph = [[] for _ in range(numCourses)] 
        in_degree = [0] * numCourses
        for node_end, node_start in prerequisites:
            graph[node_start].append(node_end)
            in_degree[node_end] += 1
            
        queue = collections.deque()
        order = []
        courses_learned = 0
        
        for i in range(len(in_degree)):
            if not in_degree[i]:
                queue.append(i)
        
        
        while queue:
            current = queue.popleft()
            order.append(current)
            courses_learned += 1
            if courses_learned == numCourses:
                return order
            for neighbor in graph[current]:
                in_degree[neighbor] -= 1
                if not in_degree[neighbor]:
                    queue.append(neighbor)
                    
        return []
        
