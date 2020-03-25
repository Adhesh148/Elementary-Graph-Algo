# Elementary-Graph-Algo
Graph Algorithms for DAA LAB Submission

#### Steps to run the Code
* Goto build directory
* Delete all of its contents
* run the following sequentially in the terminal opened at build directory
    * cmake ..
    * make
    * ./graph

Note: Install cmake in your pc if not already installed.

### Index

### Module - 1:
#### 1. DFS(Graph G)
##### Function Description
A void function that performs DFS on the graph G and prints out the DFS tree. It performs DFS untill all vertices are visited. It also keeps track of the number of connected components and prints it at the end.
Parameters:
* A object G of the graph class

##### Output
Print the DFS tree covering all vertices.
Also print the number of connected components.

#### 2. DFS(Graph G, vertex s)
##### Function Description
A void function that performs DFS on the graph G and prints out the DFS tree starting at a given source vertex s.
Parameters:
* A object G of the graph class
* integer denoting the source vertex

##### Output
Print the DFS tree starting at source vertex s.

#### 3. DFS(Graph G, vertex s, vertex t)
##### Function Description
A boolean function returns if the vertex t is reachable from vertex s using DFS.
Parameters:
* A object G of the graph class
* integer s denoting the source vertex
* integer t denoting the end vertex

##### Output
Boolean value denoting if t is reachable from s.

### Module - 2:
#### 1. BFS(Graph G)
##### Function Description
A void function that performs BFS on the graph G and prints out the BFS tree. It performs DFS untill all vertices are visited. It also keeps track of the number of connected components and prints it at the end.
Parameters:
* A object G of the graph class

##### Output
Print the BFS tree covering all vertices.
Also print the number of connected components.

#### 2. BFS(Graph G, vertex s)
##### Function Description
A void function that performs BFS on the graph G and prints out the BFS tree starting at a given source vertex s.
Parameters:
* A object G of the graph class
* integer denoting the source vertex

##### Output
Print the BFS tree starting at source vertex s.

#### 3. BFS(Graph G, vertex s, vertex t)
##### Function Description
A boolean function returns if the vertex t is reachable from vertex s using BFS.
Parameters:
* A object G of the graph class
* integer s denoting the source vertex
* integer t denoting the end vertex
##### Output
Boolean value denoting if t is reachable from s.

### Module - 3:
#### 1. BFS_SPATH(Graph G, vertex s, flag)
A void function that prints the single source shortest distance path from vertex s. The flag value denotes if the given graph is weighted or unweighted.
Parameters:
* A object G of the graph class
* integer s denoting the source vertex
* integer flag which denotes:
    * flag = 0 implies graph is unweighted
    * flag = 1 implies graph is weighted
##### Input Constraints
At the moment, the algorithm for weighted graphs is only coded to handle positive weights. 
##### Output
Prints the SPATH of all vertices from given source vertex and the respective path length.

#### 2. LPATH_TREE(Tree T)
A void function that prints the longest path in the input tree using BFS (twice).
Parameters:
* A object T of the graph class
##### Input Constraints
Input graph must be a Tree. 
##### Output
Prints the LPATH in the tree.

#### 3. LPATH_DAG(Graph G)
A void function that prints the longest path in a Directed Acyclic Graph using Topological sorting.
Parameters:
* A object G of the graph class
##### Input Constraints
Input graph must be a Directed Acyclic Graph. 
##### Output
Prints the LPATH in the input DAG.

#### 4. MAX_WEIGHT_MST(Graph G)
A void function that finds the maximum edge weight spanning tree in the input graph using modified Kruskal algorithm.
Parameters:
* A object G of the graph class
##### Input Constraints
Input graph must be a undirected.
##### Output
Prints the adjacency matrix of max weight spanning tree and also prints the maximum weight.

### Module - 4:
#### 1. Test_bipartite(Graph G)
A boolean function that test if input graph G is bipartite or not. It achieves by checking if graph is 2-colorable using BFS algorithm.
Parameters:
* A object G of the graph class
##### Output
Returns a boolean value indicating if the input graph is bipartite or not. (1/0)

#### 2. Test_articulationpoints(Graph G)
A void function that prints all the articulation points in the input graph in linear time using Tarjan's algorithm.
Parameters:
* A object G of the graph class
##### Output
Prints all the articulation points in the input graph.

#### 3. Test_bridges(Graph G)
A void function that prints all the bridges in the input graph in linear time using Tarjan's algorithm.
Parameters:
* A object G of the graph class
##### Output
Prints all the bridges (u,v) in the input graph.

### Module - 5:
#### 1. MST_Kruskal(Graph G)
A void function that finds the minimum edge weight spanning tree in the input graph using Kruskal algorithm.
Parameters:
* A object G of the graph class
##### Input Constraints
Input graph must be a undirected.
##### Output
Prints the adjacenct matrix of min weight spanning tree and also prints the minimum weight.

#### 2. MST_Prim(Graph G)
A void function that finds the minimum edge weight spanning tree in the input graph using Prim's algorithm.
Parameters:
* A object G of the graph class
##### Input Constraints
Input graph must be a undirected.
##### Output
Prints the adjacency matrix of min weight spanning tree and also prints the minimum weight.

#### 3. MST_youralgo(Graph G)
A void function that finds the minimum edge weight spanning tree in the input graph using Reverse Delete algorithm.
In the above algorithm, we first sort the edges in descending order. Then we pick the edge with the max edge weight and check if its removal makes the graph disconnected. If it does not we remove it. We proceed until we only have N-1 edges left.
Parameters:
* A object G of the graph class
##### Input Constraints
Input graph must be a undirected.
##### Output
Prints the adjacency matrix of min weight spanning tree and also prints the minimum weight.

    
