# Leetcode Patterns


| Pattern      | Subcategory    | Identifiers                                           | Approaches                                              | Visualization                                |
|--------------|----------------|-------------------------------------------------------|---------------------------------------------------------|----------------------------------------------|
| Interval     |                | Intervals like [2, 5]                                 | Save to result, then update range                       | Draw number line representation of intervals |
| Array        |                |                                                       | Sorting, trying forward and back                        |                                              |
|              | Prefix (sums)  | Problems calculating sum over range on unsorted array | Utilize prefix sums                                     | Diagram with prefix sum arrays               |
|              | Sliding Window | Problems wanting subset/substring/subarray            | R - add to window and L - remove from window            | Move L and R over array                      |
|              | Two Pointer    | Replacement, comparisions needed, or duplicates       | R/L at beginning, R/L start and end                     | Draw array and step through scenarios        |
| Backtracking |                |                                                       | Important to make .copy() before saving                 |                                              |
|              | Combinations   | Explicitly asks for combinations                      | DFS with index and subset (add, call, pop(), call)      | Draw tree of possibilities                   |
|              | Permutations   | Explicitly asks for permutations                      | Helper function, insert between every number            | Draw inserting between numbers               |
|              | Subsets        | Asks for subset or power set                          | DFS append, call, pop, call (same as combination)       | Draw tree of possiblities                    |
| Binary Tree  |                | Binary tree or BST                                    | Use main function for dfs unless other tracking needed  | Draw binary tree (left, operation, right)    |
| Dynamic      |                | Repeat operations, benefit from storing values        | Cache values in dictionary or set                       | Draw problem with supporting cache           |
| Graphs       |                |                                                       |                                                         |                                              |
|              | Dijkstra       | Calculate shortest path                               | Adjacency matrix, with minHeap - store shortest in dict | Draw graph and heap                          |
|              | Prims          | Make all nodes connect                                | Adjacency matrix, minHeap - track total path            | Draw graph and heap                          |
|              | Topological    | Find if a cycle exists                                | Adjacency matrix, dfs on every node                     | Draw graph                                   |
| Hashmap      |                | Quick retrieval, mapping values                       | Set/dict to store read quickly (map values two ways)    | Draw what you would store/map                |
| Linked List  |                | Double/Singly-linked list defined or array[index]     | Fast/Slow pointers for cycle detection                  | Draw list and pointer movement               |



Don't always try and process the solution as it would be in real life.