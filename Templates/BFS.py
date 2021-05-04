from collections import deque

queue = deque([node])
distance = {node : 0}

while queue:
    node = queue.popleft()
    for neighbour in node.get_neighbours():
        if neighbour in distance:
            continue
        queue.append(neighbour)
        distance[neighbour] = distance[node] + 1
