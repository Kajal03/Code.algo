#include<bits/stdc++.h>
#define inf 1e9
using namespace std;

class Edge
{
public:
	int src, dest,weight;
};

class Graph
{
public:
	int v, e;
	Edge *edge;

	Graph(int v, int e)
	{
		this->v = v;
		this->e = e;
		edge = new Edge[e];
	}

	void addEdge(int u, int v, int weight, int count)
	{
		edge[count].src = u;
		edge[count].dest = v;
		edge[count].weight = weight;
	}

	void bellmanFord(int src)
	{
		int distance[v];
		for(int i=0;i<v;i++)
		{
			if(i==src)
			{
				distance[i] = 0;
			}
			else
			{
				distance[i] = inf;
			}
		}

		//Relaxation Code - need to be done v-1 times
		for(int i=1;i<=v-1;i++)
		{
			//iterate over every edge
			for(int j=0;j<e;j++)
			{
				int u = edge[j].src;
				int v = edge[j].dest;
				int w = edge[j].weight;

				if(distance[u]!=inf && distance[u] + w < distance[v])	
				{
					distance[v] = distance[u] + w;
				}
			}
		}

		//check for negative weight cycles
		for(int j=0;j<e;j++)
		{
			int u = edge[j].src;
			int v = edge[j].dest;
			int w = edge[j].weight;

			if(distance[u]!=inf && distance[u] + w < distance[v])	
			{
				cout<<"Graph has negative weight cyle\n";
				return;
			}
		}

		for(int i=0;i<v;i++)
		{
			printf("%d -> %d\n",i,distance[i]);
			
		}

		return;
			
	}
};

int main()
{
	int v,e;
	cin>>v>>e;

	Graph g(v,e);

	for(int i=0;i<e;i++)
	{
		int u, v, w;
		cin>>u>>v>>w;
		g.addEdge(u,v,w,i);
	}

	g.bellmanFord(0);
}
