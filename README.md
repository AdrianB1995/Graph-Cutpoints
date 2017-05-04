# Graph-Cutpoints

Given a vertex v of graph G = (V,E), we define G-v = (V-{v}, E'), where E' = {e in E | e is not incident with v}.
Thus, the graph we get by deleting v and all edges having v as an endpoint. In which vertex v is said to be a cutpoint of an connected graph G implies G-v is not connected. 

Depth First Search (DFS) is implemented to complete this task, although Breadth First Search (BFS) could be used aswell.

Designed/Programmed in a Linux environment. Programmer: Adrian Borrego, Utilities provided by Dr. Ralph Tindell.
