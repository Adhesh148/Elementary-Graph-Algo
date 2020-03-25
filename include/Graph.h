#include "pch.h"

struct Edge
{
	int u,v,w; // (u,v) belongs to E(G)	// u->v // w -weight of the edge b/w u and v
};

class Graph
{
private:
	// BFS to check bipartitness
	void BFS_bipartite(int s);

	// Tarjan Algorithm to find Articulation points
	void DFS_Tarjan(int s);

	// Tarjan Algorithm to find Bridges
	void DFS_Bridges(int s);

	// BFS for finding ShortestPath
	void BFS_Path(int s,Graph* G);

	// Find Path b/w two vertices in a Tree(graph)
	void findPath(int u,int v,Graph bfs_tree,queue<int> path,Graph* G);

	//Topological Sorting for DAG PATHS
	void topologicalSort(stack<int> &Stack);

	//DFS Function for Topological Sort
	void topologicalSortDFS(int u,stack<int> &Stack);

	//BFS To find LPATH in Tree
	int BFS_LPATH(int u);

	//Test cyclicity
	bool isCycle(Graph MST);

	//Helper to test cyclicity
	bool DFS_test_cycle(Graph MST,int s,int parent);

	//Helper Functions for MST_youralgo()
	void DFS(Graph G,int s);

	bool isConnected(Graph G);

	//discovery array - gives time at which a vertex was discovered
	int discovery[MAX];

	//an array keeps track of the lowest level that can reached from vertex u
	int low[MAX];

	//Keeps track of time of discovery in DFS Algorithm
	int time;

	// //Keeps track of the number of subtrees
	// int child;

	// Tells if a vertex is an Articulation point
	int AP[MAX];

	//Keeps track of the max_wt in a wighted graph
	int max_wt;

public:
	//Creates an array of pointers
	int** adjMatrix;

	//Keeps track of the number of vertices
	int cnt_vertices;

	//Keeps track of the number of edges
	int cnt_edges;

	//keeps track if graph is connected
	int connected=0;

	//creates visited array
	int visit[MAX];

	//create parent array
	int parent[MAX];

	//Tests bipartitness
	int bipartite;

	//used to check colorability and bipartitness
	int color[MAX];

	//Tells if Graph is directed or not? 	1 => directed
	int direct;

	//Tells the existence of cycle
	int cycle;

	//constructor
	Graph(Edge edges[],int n,int m,int directed);	// 0 => undirected, 1=> directed graph

	//Add Edge in the adjacency matrix
	void AddEdge(Edge edges[],int m,int directed);

	//Delete edge in a Graph
	void DeleteEdge(int u,int v,int directed);

	// print the adjacency matrix
	void PrintGraph(); 

	//-------MODUDLE-1-------//

	//counts the number of connected components
	int connected_comp;

	//Runs DFS until all nodes are visited starting at vertex 0
	void DFS();

	//Runs DFS starting at vertex s
	void DFS(int s);

	//Is t reachable from s ?  returns 0 if no, 1 if yes
	int DFS(int s,int t);

	void DFS_visit(int s);

	//-------MODUDLE-2-------//

	//Run BFS
	void BFS();

	//Runs BFS starting at vertex s
	void BFS(int s);

	//Is t reachable from s ?  returns 0 if no, 1 if yes
	int BFS(int s,int t);

	void BFS_visit(int s);

	//-------MODUDLE-3-------//

	//Returns SPATH from s to each of other vertices. // flag=0 => unweighted && flag =1 => weighted
	void BFS_SPATH(int s,int flag);

	void LPATH_DAG(int s);

	void LPATH_TREE();

	void MAX_WEIGHT_MST();


	//-------MODUDLE-4-------//

	// Test Bipartitness
	bool Test_bipartite();

	// Print All Articulation points in graph G
	void Test_articulationpoints();

	//Print All Bridges in graph G
	void Test_bridges();

	//-------MODUDLE-5-------//

	void MST_Kruskal();

	void MST_Prim();

	void MST_youralgo();

};
