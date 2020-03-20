#include<bits/stdc++.h>
using namespace std;

//holi - holiday accomodation spoj

class Graph
{
	int V;
	map<int,list<pair<int, int>>> adj;

	public:

		Graph(int n)
		{
			V = n;
			
		}

		void addEdge(int u, int v, int weight)
		{
			adj[u].push_back(make_pair(v,weight));
			adj[v].push_back(make_pair(u,weight));
		}

		int dfsHelper(int u, int *count, bool* visited, int &ans)
		{
			visited[u]=true;
			count[u]=1;
			for(auto neighbour:adj[u])
			{
				if(visited[neighbour.first]==false)
				{
					count[u] += dfsHelper(neighbour.first,count,visited,ans);
					ans += 2*min(count[neighbour.first],V-count[neighbour.first])*neighbour.second;
					
				}
			}
			
			return count[u];
		}	

		void dfs()
		{
			
			int *count = new int[100]{0};
			bool *visited = new bool[100]{0};
			int ans = 0;
			dfsHelper(1,count,visited,ans);
		
			cout<<ans<<endl;
		}

};


int main()
{
	Graph g(6);
	g.addEdge(1,2,3);
	g.addEdge(2,3,4);
	g.addEdge(2,4,1);
	g.addEdge(4,5,8);
	g.addEdge(5,6,5);

	g.dfs();

}














