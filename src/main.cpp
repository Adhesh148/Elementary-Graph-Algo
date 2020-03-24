/******************************************
* AUTHOR : AdheshR*
******************************************/
#include "pch.h"
#include "Graph.h"

int main()
{
	Edge edges[] =
	{
		// pair (x, y,w) represents edge from x to y having weight w
		{0,1,2},{1,2,3},{2,0,1}

	};

	int n,m,directed =1;	// 1=> directed ;0 => undirected graph
	n=3;
	m = sizeof(edges)/sizeof(edges[0]);

	Graph graph(edges,n,m,directed);

	//graph.PrintGraph();

	//--------Module - 1------------//
	
	//graph.DFS();
	//graph.DFS(2);
	//cout<<graph.DFS(0,2)<<"\n";

	//--------Module - 2------------//

	//graph.BFS();
	//graph.BFS(4);
	//cout<<graph.BFS(0,2)<<"\n";

	//--------Module - 3------------//

	graph.BFS_SPATH(1,0);			//flag = 0 => unweighted graph(wts = 1) && flag = 1 => weighted graph
	//graph.LPATH_DAG(1);			//check if ip is dag
	//graph.LPATH_TREE();			//conditional check for tree

	//--------Module - 4------------//
	
	//cout << graph.Test_bipartite()<<endl;
	//graph.Test_articulationpoints();
	//graph.Test_bridges();

	//--------Module - 5------------//

	//graph.MST_Kruskal();
	//graph.MST_Prim();

	//graph.PrintGraph();

}