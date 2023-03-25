"""
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
"""


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        """
        Trying to find a cycle in the graph
        """
        # initialize adjacency matrix
        adj = {}
        for i in range(numCourses):
            adj[i] = []

        # populate adjacency matrix
        for pre in prerequisites:
            adj[pre[1]].append(pre[0])

        path = []

        # dfs - postorder
        def dfs(src):
            if src in path: # prerequisite rule broken
                return False
            if adj[src] == []:
                return True
            
            path.append(src)
            
            for neighbors in adj[src]:
                if not dfs(neighbors): return False # stop and return false
                path.pop()
                adj[src] = [] # do not dfs again on src
                return True


        # call dfs
        for i in range(numCourses):
            if not dfs(i): return False # stop and return false

        return True





         