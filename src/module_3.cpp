#include "pch.h"
#include "Graph.h"

void Graph:: BFS_SPATH(int s,int flag)
{
	if(flag ==0)
	{
		//Initialize for BFS call
		fill(visit,visit+cnt_vertices,0);
		BFS_Path(s);

		//Revert Adjacenct Matrix to original form if directed.
		if(flag == 1)
			for(int i=0;i<cnt_vertices;++i)
				for(int j=0;j<cnt_vertices;++j)
					if(adjMatrix[i][j]>0)
						adjMatrix[i][j] = adjMatrix[i][j]-max_wt;
	}
}


void Graph:: BFS_Path(int s)
{
	visit[s] = 1;
	queue<int> Q;
	Q.push(s);
	int u;

	//Instantiate a new Graph to keep track of the bfs tree
	Edge tree_edges[1];
	Graph bfs_tree({},cnt_vertices,0,0);	//undirected tree having 0 edges

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
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
	}
	//bfs_tree.PrintGraph();
	for(int i=0;i<cnt_vertices;++i)
	{
		cout << "SPATH B/W "<<s<<" and "<<i<<endl;
		fill(visit,visit+cnt_vertices,0);
		queue<int> path;
		findPath(s,i,bfs_tree,path);
	}
}

void Graph:: findPath(int u,int v,Graph bfs_tree,queue<int> path)
{
	visit[u] = 1;
	path.push(u);

	if(path.back() == v)
	{
		while(!path.empty())
		{
			cout << path.front()<<" ";
			path.pop();
		}
		cout << "\n";
	}
	else
		for(int i=0;i<cnt_vertices;++i)
			if(bfs_tree.adjMatrix[u][i] == 1 && visit[i] == 0)
					findPath(i,v,bfs_tree,path);

	path.pop();
	visit[u] = 0;
}

void Graph:: LPATH_DAG(int s) 	// FOR DAG.
{
	stack<int> Stack;
	int dist[cnt_vertices];

	fill(dist,dist+cnt_vertices,NINF);	// initialize to Negative Infinity(MIN_INT)	

	dist[s] = 0;

	topologicalSort(Stack);

	while(!Stack.empty())
	{
		int u = Stack.top();
		Stack.pop();

		if(dist[u]!=NINF)
		{
			for(int v=0;v<cnt_vertices;++v)
				if((adjMatrix[u][v] != 0) && (dist[v]<(dist[u]+adjMatrix[u][v])))
					dist[v] = dist[u]+adjMatrix[u][v];
		}
		
	}

	cout << "LPATH from "<<s<<" to"<<endl;
	for(int i=0;i<cnt_vertices;++i)
	{
		if(dist[i] == NINF)
			cout << i<<" INF"<<endl;
		else
			cout << i<<" "<<dist[i]<<endl;
	}

	// Find the LPATH - find vertex with max LPATH and findPATH for the source and that vertex
	// Edge tree_edges[1];
	// Graph tree({},cnt_vertices,0,1);
	// for(int i=0;i<cnt_vertices;++i)
	// {
	// 	for(int j=0;j<cnt_vertices;++j)
	// 	{	
	// 		tree_edges[0].u = i;
	// 		tree_edges[0].v = j;
	// 		tree_edges[0].w = adjMatrix[i][j];
	// 		if(adjMatrix[i][j]!=0)
	// 			tree_edges[0].w = 1;
	// 		tree.AddEdge(tree_edges,1,1);
	// 	}
	// }

	// fill(visit,visit+cnt_vertices,0);
	// queue<int> path;
	// findPath(1,4,tree,path);
}

void Graph:: topologicalSort(stack<int> &Stack)
{
	fill(visit,visit+cnt_vertices,0);

	for(int i=0;i<cnt_vertices;++i)
		if(visit[i] == 0)
			topologicalSortDFS(i,Stack);
}

void Graph:: topologicalSortDFS(int u,stack<int> &Stack)
{
	visit[u] = 1;
	for(int i=0;i<cnt_vertices;++i)
		if(adjMatrix[u][i] != 0 && visit[i] == 0)
			topologicalSortDFS(i,Stack);

	Stack.push(u);
}

// Seems to be working fine for a positively weighted tree
void Graph:: LPATH_TREE()
{
	int s,t,s_dist;
	s = BFS_LPATH(0);
	t = BFS_LPATH(s);
	cout << "LPATH is from "<<s<<" to "<<t<<" of length "<<discovery[t]<<endl;

}

int Graph :: BFS_LPATH(int s)
{
	fill(discovery,discovery+cnt_vertices,-1);
	discovery[s] = 0;
	queue<int> Q;
	Q.push(s);
	int u;
	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(int i=0;i<cnt_vertices;++i)
		{
			if(adjMatrix[u][i] != 0 && discovery[i] == -1)
			{
				Q.push(i);
				discovery[i] = discovery[u]+adjMatrix[u][i];
			}
		}
	}

	int max_index,max_dist =0;

	for(int i=0;i<cnt_vertices;++i)
	{
		if(discovery[i]>max_dist)
		{
			max_dist = discovery[i];
			max_index = i;
		}
	}
	return max_index;
}