#include "pch.h"
#include "Graph.h"

bool Graph:: Test_bipartite()
{
	fill(color,color+cnt_vertices,0);
	fill(visit,visit+cnt_vertices,0);
	fill(parent,parent+cnt_vertices,0);
	bipartite =0;

	for(int i=0;i<cnt_vertices;++i)
		if(visit[i] == 0)
			BFS_bipartite(i);

	if(bipartite == 0)
		return 1;

	return 0;
}

void Graph:: BFS_bipartite(int s)
{
	color[s] = 1; 		// 1 represents red, 2 represents blue
	visit[s] = 1;
	queue<int> Q;
	Q.push(s);
	int u;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(int i=0;i<cnt_vertices;++i)
		{
			if(adjMatrix[u][i] != 0)
			{
				if(color[i] == 0)
					color[i] = 3 - color[u];
				else if(color[i]!=0 && color[i] == color[u])
					++bipartite;

				if(visit[i] == 0)
				{
					visit[i] = 1;
					parent[i] = u;
					Q.push(i);
				}
			}
		}
	}
}

void Graph:: Test_articulationpoints()
{
	fill(visit,visit+cnt_vertices,0);
	fill(parent,parent+cnt_vertices,-1);
	fill(low,low+cnt_vertices,0);
	fill(discovery,discovery+cnt_vertices,0);
	fill(AP,AP+cnt_vertices,0);
	time =0;
	for(int i=0;i<cnt_vertices;++i)
	{
		if(visit[i] == 0)
			DFS_Tarjan(i);
	}

	cout << "ARTICULATION POINTS:\n";
	for(int j=0;j<cnt_vertices;++j)
		if(AP[j] == 1)
			cout << j<<" ";
	cout << "\n";
}

void Graph:: DFS_Tarjan(int s)
{
	visit[s] = 1;
	low[s] = discovery[s] = ++time;
	int child =0;
	for(int i=0;i<cnt_vertices;++i)
	{
		if(adjMatrix[s][i] != 0)
		{
			if(visit[i] == 0)
			{
				++child;
				parent[i] = s;
				DFS_Tarjan(i);

				low[s] = min(low[s],low[i]);

				if(parent[s]!=-1 && (low[i]>=discovery[s]))
					AP[s] = 1;
				if(parent[s]==-1 && (child>1))
					AP[s] = 1;
			}
			else if(i!=parent[s])
				low[s] = min(low[s],discovery[i]);
		}
	}
}


void Graph:: Test_bridges()
{
	fill(visit,visit+cnt_vertices,0);
	fill(parent,parent+cnt_vertices,-1);
	fill(low,low+cnt_vertices,0);
	fill(discovery,discovery+cnt_vertices,0);
	time =0;
	cout << "Bridges:\n";
	for(int i=0;i<cnt_vertices;++i)
	{
		if(visit[i] == 0)
			DFS_Bridges(i);
	}
}

void Graph:: DFS_Bridges(int s)
{
	visit[s] = 1;
	low[s] = discovery[s] = ++time;

	for(int i=0;i<cnt_vertices;++i)
	{
		if(adjMatrix[s][i] != 0)
		{
			if(visit[i] == 0)
			{
				parent[i] = s;
				DFS_Bridges(i);

				low[s] = min(low[s],low[i]);

				if(low[i]>discovery[s])
					cout << s<<" "<<i<<endl;
			}
			else if(i!=parent[s])
				low[s] = min(low[s],discovery[i]);
		}
	}
}
