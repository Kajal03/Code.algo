#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graphs
{
	T vertices;
	map<T, list<T>> adjacency_list;

    public:
	Graphs(int v)
	{
		vertices = v;
		//adjacency_list = new list<T>[v];
	}

	void addEdge(T v1, T v2)
	{
		//v1--;
		//v2--;
		adjacency_list[v1].push_back(v2);
		adjacency_list[v2].push_back(v1);
	}

	void print()
	{
		for(auto x:adjacency_list)
		{
			cout<<x.first<<"->";
			for(auto y:x.second)
				cout<<y<<",";
			cout<<endl;
		}
	}

	void breadthFirstSearch(T source)
	{
		queue<T> q;
		unordered_map<T, bool> visited;
		q.push(source);
		visited[source]=true;
		while(!q.empty())
		{
			T node = q.front();
			cout<<node<<" ";
			q.pop();
			for(auto x: adjacency_list[node])
			{
				if(visited[x]!=true)
				{
					q.push(x);
					visited[x]=true;
				}
			}
		}
	}

	void singleSourceShortestDistance(T source)
	{
		unordered_map<T, int> distance;
		queue<T> q;
		unordered_map<T, T> parent;

		for(auto x: adjacency_list)
		{
			distance[x.first] = INT8_MAX;
		}

		parent[source] = source;
		distance[source] = 0;

		q.push(source);
		
		while(!q.empty())
		{
			T node = q.front();
			q.pop();
			
			for(auto x: adjacency_list[node])
			{
				if(distance[x]==INT8_MAX)
				{	
					q.push(x);
					parent[x] = node;
					distance[x] = distance[node] + 1;
				}
			}
		}

		for(auto x: adjacency_list)
		{
			cout<<x.first<<" "<<distance[x.first]<<endl;
		}
		
	}
};

int main()
{
	Graphs<char> g(5);
	g.addEdge('a','b');
	g.addEdge('b','c');
	//g.addEdge('a','c');
	g.addEdge('c','d');
	g.addEdge('a','e');

//	g.breadthFirstSearch('a');
	g.singleSourceShortestDistance('a');
}
