"""
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
"""

class Solution:
    def minCostConnectPoints(self, points: List[List[int]]) -> int:
        # adjacency matrix
        adj = {}
        for i in range(len(points)+1):
            adj[i] = []

        for p1 in range(len(points)): 
            for p2 in range(p1+1, len(points)):
                adj[p1].append((abs(points[p1][0] - points[p2][0]) \
                    + abs(points[p1][1] - points[p2][1]), p2))

        shortest = {}
        minHeap = [(0, 0)]
        path = 0

        # shortest path with prims
        while minHeap:
            weight, dst = heapq.heappop(minHeap)
            if dst in shortest:
                continue
            shortest[dst] = weight
            path += weight

            for weight, dst in adj[dst]:
                if dst not in minHeap:
                    heapq.heappush(minHeap, (weight, dst))
        
        return path
            