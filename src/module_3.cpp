#include "pch.h"
#include "Graph.h"

void Graph:: BFS_SPATH(int s,int flag)
{

	//Unweighted Graphs
	if(flag ==0)
	{
		//Initialize for BFS call
		fill(visit,visit+cnt_vertices,0);
		BFS_Path(s,this);
	}
	//Weighted Graphs
	else if(flag == 1)		
	{
		/*
		Assumption about the weights is that they are poitive integers.
		Cases like negative and fractional should be included.
		*/

		//Create a copy of adjacency Matrix so as to preserve the original matrix
		int **array = new int*[cnt_vertices];
		for(int i=0;i<cnt_vertices;++i)
			array[i] = new int[cnt_vertices];

		for(int i=0;i<cnt_vertices;++i)
			for(int j=0;j<cnt_vertices;++j)
				array[i][j] = adjMatrix[i][j];

		// tells us how many dummy vertices are needed in the new graph
		int dummy_vertices;	
		int end_j;
		for(int i=0;i<cnt_vertices;++i)
		{
			end_j = cnt_vertices;
			if(direct == 0)
				end_j = i;
			for(int j=0;j<end_j;++j)
				if(adjMatrix[i][j]>0)
					dummy_vertices = dummy_vertices + adjMatrix[i][j]-1;
		}
		
		//create the graph with the dummy edges.
		Graph temp_graph(NULL,cnt_vertices+dummy_vertices,cnt_edges+dummy_vertices,direct);
		temp_graph.cnt_vertices = cnt_vertices+dummy_vertices;
		temp_graph.cnt_edges = cnt_edges+dummy_vertices;

		//Assign the edges with wts 1/0
		//Initialize all cells in new matrix to 0.
		for(int i=0;i<temp_graph.cnt_vertices;++i)
			fill(temp_graph.adjMatrix[i],temp_graph.adjMatrix[i]+temp_graph.cnt_vertices,0);

		int index = cnt_vertices;		// marks the starting row of the dummy vertices
		for(int i=0;i<cnt_vertices;++i)
		{
			for(int j=0;j<cnt_vertices;++j)
			{
				if(array[i][j] == 1)
				{
					temp_graph.adjMatrix[i][j] = 1;
					--array[i][j];
					if(direct == 0)
					{
						temp_graph.adjMatrix[j][i] = 1;
						--array[j][i];
					}
				}
				else if(array[i][j] > 1)
				{
					temp_graph.adjMatrix[i][index] = 1;
					--array[i][j];
					if(direct == 0)
					{
						temp_graph.adjMatrix[index][i] = 1;
						--array[j][i];
					}
					while(array[i][j]>1)
					{
						temp_graph.adjMatrix[index][index+1] = 1;
						--array[i][j];
						if(direct ==0)
						{
							temp_graph.adjMatrix[index+1][index] = 1;
							--array[j][i];
						}
						++index;						
					}
					temp_graph.adjMatrix[index][j] = 1;
					--array[i][j];
					
					if(direct == 0)
					{
						temp_graph.adjMatrix[j][index] = 1;
						--array[j][i];
					}
					++index;
				}
			}
		}
		//call BFS path from the source.
		BFS_Path(s,&temp_graph);
	}
}


void Graph:: BFS_Path(int s,Graph* G)
{
	visit[s] = 1;
	queue<int> Q;
	Q.push(s);
	int u;

	//Instantiate a new Graph to keep track of the bfs tree
	Edge tree_edges[1];
	Graph bfs_tree(NULL,G->cnt_vertices,0,0);	//undirected tree having 0 edges

	while(!Q.empty())
	{
		u = Q.front();
		Q.pop();
		for(int i=0;i<G->cnt_vertices;++i)
		{
			if(G->adjMatrix[u][i] != 0)
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
		fill(visit,visit+G->cnt_vertices,0);
		queue<int> path;
		findPath(s,i,bfs_tree,path,G);
	}
}

void Graph:: findPath(int u,int v,Graph bfs_tree,queue<int> path,Graph* G)
{
	visit[u] = 1;
	int distance =0;
	path.push(u);

	if(path.back() == v)
	{
		while(!path.empty())
		{
			++distance;
			cout << path.front()<<" ";
			path.pop();
		}
		cout <<"\nPath length: "<<distance-1<<endl;
		//cout << "\n";
	}
	else
	{
		for(int i=0;i<G->cnt_vertices;++i)
		{
			distance =0;
			if(bfs_tree.adjMatrix[u][i] == 1 && visit[i] == 0)
					findPath(i,v,bfs_tree,path,G);
		}
	}

	path.pop();
	visit[u] = 0;
}

void Graph::LPATH_DAG()
{
	int lpath =-1,u,v;
	for(int i=0;i<cnt_vertices;++i)
	{
		pair<int,int> max;
		max = LPATH_DAG_util(i);
		if(max.second>lpath)
		{
			u = i;
			lpath = max.second;
			v = max.first;
		}
	}

	cout << "LONGEST PATH IN THE DAG IS FROM "<<u<<" TO "<<v<<" OF LENGTH "<<lpath<<endl;
}

pair<int,int> Graph:: LPATH_DAG_util(int s) 	// FOR DAG.
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

	int max_v,max_d;
	for(int i=0;i<cnt_vertices;++i)
	{
		if(dist[i] != NINF && dist[i]>max_d)
		{
				max_d = dist[i];
				max_v = i;
		}
	}

	pair<int,int> max;
	max.first = max_v;
	max.second = max_d;

	return max;


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

bool comparePairsDesc(const std::pair<pair<int,int>,int>& lhs, const std::pair<pair<int,int>,int>& rhs)
{
  return lhs.second > rhs.second;		// Change sign to get MAX_WEIGHT_SPAN_TREE
}

void Graph:: MAX_WEIGHT_MST()
{
	Graph MST(NULL,cnt_vertices,0,0);	// undirected MST

	vector<pair<pair<int,int>,int>> v(cnt_edges);		// Make pairs of ((u,v),w), then sort by w.
	int cnt = 0;

	for(int i=0;i<cnt_vertices;++i)
	{	
		for(int j=0;j<i;++j)						// Considering only one half of adjMatrix since it is an undirected graph
		{
			if(adjMatrix[i][j] !=0)			 
			{
				v[cnt].first = make_pair(i,j);
				v[cnt++].second = adjMatrix[i][j];
			}
		}
	}

	sort(v.begin(), v.end(),comparePairsDesc);

	Edge MST_edges[1];
	int iter =0,mst_weight=0;

	while(MST.cnt_edges!=(cnt_vertices-1))
	{
		MST_edges[0].u = v[iter].first.first;
		MST_edges[0].v = v[iter].first.second;
		MST_edges[0].w = v[iter].second;
		MST.AddEdge(MST_edges,1,0);

		if(isCycle(MST) == 1)
			MST.DeleteEdge(MST_edges[0].u,MST_edges[0].v,0);		// parameters are (u,v,directed?)
		else
			mst_weight = mst_weight+MST_edges[0].w;

		++iter;
	}

	MST.PrintGraph();
	cout << mst_weight<<endl;

}