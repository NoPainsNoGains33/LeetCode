class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows, columns = len(grid), len(grid[0])
        visited = set()
        num_of_islands = 0
        for i in range(rows):
            for j in range(columns):
                if grid[i][j] == "0" or (i, j) in visited:
                    continue
                # It is a new 1
                self.bfsHelper(i, j, visited, grid)
                num_of_islands += 1
        
        return num_of_islands
    
    def bfsHelper(self, i, j, visited, grid):
        queue = collections.deque([(i, j)])
        visited.add((i, j))
        
        while queue:
            current_coordinate = queue.popleft()
            for next_coordinate in self.findNextCoordinates(current_coordinate, visited, grid):
                queue.append(next_coordinate)
                visited.add(next_coordinate)
                
    def findNextCoordinates(self, current_coordinate, visited, grid):
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        rows, columns = len(grid), len(grid[0])
        nexts = []
        for direction in directions:
            currentX = current_coordinate[0] + direction[0]
            currentY = current_coordinate[1] + direction[1]
            if currentX < rows and currentX >=0 and currentY < columns and currentY >= 0:
                if grid[currentX][currentY] == "1" and (currentX, currentY) not in visited:
                    nexts.append((currentX, currentY))
                    
        return nexts
