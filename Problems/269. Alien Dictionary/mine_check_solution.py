# 这题时空复杂度有点麻烦
# 这题只需要比相邻的两个words的字典序
# 假设len(words) = N, total length = C (N * avg(L)), # of unique words = U, U at most 26
# 时间复杂度: 计算graph, 最坏O(C) in_degree, 一共 N - 1个相邻关系 因为两两之间只能产生一对大小关系, BFS O(V + E), O(U + min(U ^ 2, N - 1))
# 总的算下来就是O(C)
# 空间复杂度 最多 O(26 * 26), O(1)
class Solution:
    def alienOrder(self, words: List[str]) -> str:
        graph = self.buildGraph(words)
        if not graph:
            return ""
        in_degree = self.calculateIndegree(graph)
        print(graph)
        print(in_degree)
        order = self.toplogicalSort(graph, in_degree)
        
        return order if len(order) == len(graph) else ""
    
    def buildGraph(self, words):
        # Find all letters
        graph = {}
        for word in words:
            for char in word:
                if char not in graph:
                    graph[char] = set()
                    
        # Find letter neighbors(dependency)
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                previous = words[i]
                later = words[j]
                for k in range(min(len(previous), len(later))):
                    if previous[k] != later[k]:
                        graph[previous[k]].add(later[k])
                        break
                    # ["abc", "ab"] is not valid
                    if k == len(later) -1 and len(previous) > len(later):
                        return None
        
        return graph
    
    def calculateIndegree(self, graph):
        in_degree = {node : 0 for node in graph}
        for node in graph:
            for neigbor in graph[node]:
                in_degree[neigbor] += 1
                
        return in_degree
    
    def toplogicalSort(self, graph, in_degree):
        queue = collections.deque()
        # Find all nodes with indegree = 0 and push them in queue
        for node, in_degrees in in_degree.items():
            if in_degrees == 0:
                queue.append(node)
        
        order = ""
        while queue:
            node = queue.popleft()
            order += node
            for neighbor in graph[node]:
                in_degree[neighbor] -= 1
                if in_degree[neighbor] == 0:
                    queue.append(neighbor)
                    
        return order
                
                
