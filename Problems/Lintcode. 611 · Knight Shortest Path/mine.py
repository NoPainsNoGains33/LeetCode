"""
Definition for a point.
class Point:
    def __init__(self, a=0, b=0):
        self.x = a
        self.y = b
"""

DIRECTIONS = [
    (-2, -1), (-2, 1), (-1, 2), (1, 2),
    (2, 1), (2, -1), (1, -2), (-1, -2),
]

class Solution:
        
    """
    @param grid: a chessboard included 0 (false) and 1 (true)
    @param source: a point
    @param destination: a point
    @return: the shortest path 
    """
    def shortestPath(self, grid, source, destination):
        if not grid or not grid[0]:
            return -1

        queue = collections.deque([(source.x, source.y)])
        distance = {(source.x, source.y) : 0}

        while queue:
            current_point = queue.popleft()
            if current_point[0] == destination.x and current_point[1] == destination.y:
                return distance[current_point]
            for direction in DIRECTIONS:
                next_point = Point(
                    current_point[0]+ direction[0], 
                    current_point[1] + direction[1],
                    )
                if self.isValid(next_point, grid, distance):
                    distance[(next_point.x, next_point.y)] = distance[current_point] + 1
                    queue.append((next_point.x, next_point.y))

        return -1

    def isValid(self, next_point, grid, distance):
        row, column = len(grid), len(grid[0])
        if next_point.x < 0 or next_point.x >= row:
            return False
        if next_point.y < 0 or next_point.y >= column:
            return False
        if (next_point.x, next_point.y) in distance:
            return False
        
        return grid[next_point.x][next_point.y] == 0
