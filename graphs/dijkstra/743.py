"""
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
"""


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        # dijisktra - shortest path
        # s = src, d = dst, w = weight
        # shortest path, len(shortest) != len(times)
        # time = addition of weights

        # adjacency matrix
        adj = {}
        for i in range(1, n+1):
            adj[i] = [] # list of adjacent nodes

        # populate the adjacency matrix
        for s, d, w in times:
            adj[s].append((d, w))

        shortest = {}
        minHeap = [(0, k)]
        t = 0
        while minHeap:
            w1, n1 = heapq.heappop(minHeap)
            if n1 in shortest:
                continue
            shortest[n1] = w1
            t = max(t, w1)

            # populate the heap
            for n2, w2 in adj[n1]:
                if n2 not in shortest:
                    heapq.heappush(minHeap, (w1 + w2, n2))

        return t if len(shortest) == n else -1
