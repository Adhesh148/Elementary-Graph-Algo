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
		{0,1,4},{1,2,8},{2,3,7},{3,4,9},{4,5,10},{5,6,2},{6,7,1},{7,0,8},
		{1,7,11},{7,8,7},{2,8,2},{8,6,6},{2,5,4},{3,5,14}

	};

	int n,m,directed =0;	// 1=> directed ;0 => undirected graph
	n=9;
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

	//graph.BFS_SPATH(1,0);			//flag = 0 => unweighted graph(wts = 1) && flag = 1 => weighted graph
	//graph.LPATH_DAG(1);			// *check if ip is dag (optional)
	//graph.LPATH_TREE();			// *add conditional check for tree (optional)
	//graph.MAX_WEIGHT_MST();

	//--------Module - 4------------//
	
	//cout << graph.Test_bipartite()<<endl;
	//graph.Test_articulationpoints();
	//graph.Test_bridges();

	//--------Module - 5------------//

	//graph.MST_Kruskal();
	//graph.MST_Prim();
	//graph.MST_youralgo();

	//graph.PrintGraph();

}