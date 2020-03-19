#include "pch.h"
#include "Graph.h"

void Graph:: BFS()
{
	fill(visit,visit+cnt_vertices,0);
	connected_comp=0;

	cout << "BFS: \n";
	for(int i=0;i<cnt_vertices;++i)
	{
		if(visit[i] == 0)
		{
			BFS_visit(i);
			++connected_comp;
			printf("\n");
		}
	}
	cout <<"No of Connected Components: "<<connected_comp<<"\n";
}

void Graph:: BFS(int s)
{
	fill(visit,visit+cnt_vertices,0);
	cout << "BFS starting at "<<s<<":\n";
	BFS_visit(s);
	cout << "\n";
}

int Graph::BFS(int s,int t)
{
	fill(visit,visit+cnt_vertices,0);
	BFS_visit(s);
	cout << "\n";
	return visit[t];
}

void Graph:: BFS_visit(int s)
{
	visit[s] = 1;
	queue<int> Q;
	Q.push(s);
	int u;
	while(!Q.empty())
	{
		u = Q.front();
		cout << u<<" ";
		Q.pop();
		for(int i=0;i<cnt_vertices;++i)
		{
			if(adjMatrix[u][i] != 0 && visit[i] == 0)
			{
				visit[i] = 1;
				Q.push(i);
			}
		}
	}
}