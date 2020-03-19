	/******************************************
* AUTHOR : AdheshR*
******************************************/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define N 100000
#define MOD 1000000007
#define dd double


int sum(int x,int y,int flag=0);
int sum(int x,int y,int flag=1);


int main()
{
	cout << sum(7,4);
}

int sum(int x,int y)
{
	return x+y;
}

int sum(int x,int y,int flag=1)
{
	return x-y;
}


void Graph:: Test_articulationpoints()
{
	fill(visit,visit+cnt_vertices,0);
	fill(parent,parent+cnt_vertices,-1);
	fill(low,low+cnt_vertices,0);
	fill(discovery,discovery+cnt_vertices,0);
	fill(AP,AP+cnt_vertices,0);
	time =0;

	// for(int i=0;i<cnt_vertices;++i)
	// {
	// 	if(visit[i] == 0)
	// 		DFS_Tarjan(i);
	// }

	// for (int i=0;i<cnt_vertices;++i)
	// 	if(AP[i] == 1)
	// 		cout << i<<" ";
}

void Graph:: DFS_Tarjan(int s)
{
	visit[s] = 1;
	low[s] = discovery[s] = ++time;
	int child =0;
	for(int i=0;i<cnt_vertices;++i)
	{
		if(adjMatrix[s][i] == 1)
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



// MODULE -3 BFS_Path 

		for(int i=0;i<cnt_vertices;++i)
		{
			if(adjMatrix[u][i] == 1)
			{
				if(visit[i] == 0)
				{
					visit[i] = 1;
					tree_edges[0].u = u,tree_edges[0].v = i,tree_edges[0].w =1;
					bfs_tree.AddEdge(tree_edges,1,0);
					Q.push(i);
				}
			}
		}



for(int i=0;i<cnt_vertices;++i)
		{
			if(adjMatrix[u][i] > 0)
			{
				neighbors[0].push_back(i);					// position of vertex i
				neighbors[1].push_back(adjMatrix[u][i]);	//weight of u-i edge
			}
		}

		SortNeighbors(neighbors);

		for(int i=0;i<neighbors[0].size();++i)
		{
			if(visit[neighbors[0][i]] == 0)
			{
				visit[neighbors[0][i]] = 1;
				tree_edges[0].u = u,tree_edges[0].v = neighbors[0][i],tree_edges[0].w = neighbors[1][i];
				bfs_tree.AddEdge(tree_edges,1,0);
				Q.push(neighbors[0][i]);
			}
		}



		//Helper Function
void SortNeighbors(vector<vector<int>> &neighbors)
{
	int temp;
	for(int i=0;i<neighbors[0].size();++i)
	{
		for(int j=0;j<neighbors[0].size()-i-1;++j)
		{
			if(neighbors[0][j]<neighbors[0][j+1])
			{
				temp = neighbors[0][j];
				neighbors[0][j] = neighbors[0][j+1];
				neighbors[0][j+1] = temp;

				temp  = neighbors[1][j];
				neighbors[1][j] = neighbors[1][j+1];
				neighbors[1][j+1] = temp;
			}
		}
	}
} 