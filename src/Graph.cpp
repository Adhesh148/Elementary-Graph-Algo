#include "pch.h"
#include "Graph.h"

Graph::Graph(Edge edges[],int n,int m,int directed)	// 0 => undirected, 1=> directed graph
{
	//create new n instances of pointers
	adjMatrix = new int*[n];

	cnt_vertices = n;
	cnt_edges = 0;
	direct = directed;

	//Initialize each of the n pointers and assign initial weights 0
	for(int i=0;i<n;++i)
	{
		adjMatrix[i] = new int[n];
		fill(adjMatrix[i],adjMatrix[i]+n,0);
	}

	AddEdge(edges,m,directed);
}

void Graph:: AddEdge(Edge edges[],int m,int directed)
{
	for(int i=0;i<m;++i)
	{
		adjMatrix[edges[i].u][edges[i].v] = edges[i].w;
		if(directed == 0)
		{
			adjMatrix[edges[i].v][edges[i].u] = edges[i].w;	
		}
		++cnt_edges;
	}
}

void Graph:: DeleteEdge(int u,int v,int directed)
{
	adjMatrix[u][v] = 0;
	if(directed == 0)
		adjMatrix[v][u] = 0;

	--cnt_edges;
}

void Graph:: PrintGraph()
{
	for(int i=0;i<cnt_vertices;++i)
	{
		for(int j=0;j<cnt_vertices;++j)
			cout << adjMatrix[i][j]<<" ";
		cout << "\n";
	}
}