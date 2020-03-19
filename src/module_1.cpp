#include "pch.h"
#include "Graph.h"


void Graph:: DFS()
{
	fill(visit,visit+cnt_vertices,0);
	connected_comp =0;
	cout << "DFS: \n";
	for(int i=0;i<cnt_vertices;++i)
	{
		if(visit[i] == 0)
		{
			DFS_visit(i);
			++connected_comp;
			printf("\n");
		}
	}
	cout <<"No of Connected Components: "<<connected_comp<<"\n";
}

void Graph::DFS(int s)
{
	fill(visit,visit+cnt_vertices,0);
	cout << "DFS starting at "<<s<<":\n";
	DFS_visit(s);
	cout << "\n";
}

int Graph::DFS(int s,int t)
{
	fill(visit,visit+cnt_vertices,0);
	DFS_visit(s);
	cout << "\n";
	return visit[t];
}

void Graph:: DFS_visit(int s)
{
	visit[s] = 1;
	cout << s<<" ";
	for(int i=0;i<cnt_vertices;++i)
	{
		if(adjMatrix[s][i] != 0 && visit[i] == 0)
			DFS_visit(i);
	}
}