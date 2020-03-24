#include "pch.h"
#include "Graph.h"

bool comparePairs(const std::pair<pair<int,int>,int>& lhs, const std::pair<pair<int,int>,int>& rhs)
{
  return lhs.second < rhs.second;		// Change sign to get MAX_WEIGHT_SPAN_TREE
}

// Find MST in an undirected connected graph
void Graph:: MST_Kruskal()
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

	sort(v.begin(), v.end(),comparePairs);

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

//Checks if given Graph contains cycle.
bool Graph:: isCycle(Graph MST)
{	
	fill(visit,visit+cnt_vertices,0);
	for(int i=0;i<cnt_vertices;++i)
		if(visit[i] == 0)
			if(DFS_test_cycle(MST,i,-1) == 1)
				return 1;
	return 0;
}

bool Graph:: DFS_test_cycle(Graph MST,int s,int parent)
{
	visit[s] = 1;
	for(int i=0;i<cnt_vertices;++i)
	{
		if(MST.adjMatrix[s][i]!=0)
		{
			if(visit[i] == 0)
			{
				if(DFS_test_cycle(MST,i,s) == 1)
					return 1;
			}
			else if(parent!=i)
				return 1;
		}
	}
	return 0;
}


void Graph:: MST_Prim()
{
	Graph MST(NULL,cnt_vertices,0,0);	// undirected MST 
	Edge MST_edges[1];

	int mst_weight=0;
	vector<int> MSTSet;	//Keeps track of vertices included in the MST

	int key[cnt_vertices];
	fill(key,key+cnt_vertices,INF);

	//Pick 0th vertex first
	key[0] = 0;

	int min_key,min_index;

	while(MSTSet.size()!=cnt_vertices)
	{
		min_key=INF;
		for(int i=0;i<cnt_vertices;++i)
		{
			if(find(MSTSet.begin(),MSTSet.end(),i)==MSTSet.end())
			{
				if(key[i]<min_key)
				{
					min_key = key[i];
					min_index =i;
				}
			}
		}

		for(int i=0;i<MSTSet.size();++i)
		{
			if(adjMatrix[MSTSet[i]][min_index]  == min_key )
			{
				MST_edges[0].u = MSTSet[i];
				MST_edges[0].v = min_index;
				MST_edges[0].w = adjMatrix[MSTSet[i]][min_index];
				MST.AddEdge(MST_edges,1,0);
				break;
			}
		}
		MSTSet.push_back(min_index);
		mst_weight = mst_weight+key[min_index];
		for(int i=0;i<cnt_vertices;++i)
		{
			if(adjMatrix[min_index][i] !=0)
			{
				if(adjMatrix[min_index][i]<key[i])
					key[i] = adjMatrix[min_index][i];
			}
		}
	}

	MST.PrintGraph();
	cout << mst_weight<<endl;
}