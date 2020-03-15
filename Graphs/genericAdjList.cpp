#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graphs
{
	T vertices;
	map<T, list<T>> adjacency_list;

    public:
	/*Graphs(int v)
	{
		vertices = v;
		//adjacency_list = new list<T>[v];
	}
*/
	void addEdge(T v1, T v2, bool bidirectional=true)
	{
		//v1--;
		//v2--;
		adjacency_list[v1].push_back(v2);
		if(bidirectional)
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

	void dfsHelper(T source, unordered_map<T, bool> &visited)
	{

		visited[source] = true;
		cout<<source<<" ";
		for(auto x:adjacency_list[source])
		{
			if(visited[x]!=true)
			{
				dfsHelper(x, visited);
			}
		}
	}

	void depthFirstSearch(T source)
	{
		unordered_map<T, bool> visited;
		int components = 0;

		for(auto x : adjacency_list)
		{	
			if(visited[x.first]==false)
			{
				dfsHelper(x.first, visited);		
				components++;
			}
		}
	
		cout<<"\nNumber of components in the graph is "<<components<<endl;

	}

	void tsDFSHelper(T node, unordered_map<T,bool> &visited, list<T> &ordering)
	{
		visited[node]=true;
		for(auto x:adjacency_list[node])
		{
			if(visited[x]==false)
				tsDFSHelper(x,visited, ordering);
		}
		//by the time it reach here, it must have visited all its children, so it is safe to add this in ordering
		ordering.push_front(node);
	}

	void topologicalSortDFS()
	{
		unordered_map<T,bool> visited;
		list<T> ordering;
		
		for(auto x: adjacency_list)
		{
			if(visited[x.first]==false)
			{
				tsDFSHelper(x.first, visited, ordering);
			}
		}

		for(auto y:ordering)
		{
			cout<<y<<" --> ";
		}
		cout<<endl;
	}

	bool isCyclic(T source) //cycle detection in undirected graph using BFS
	{
		unordered_map<T, bool> visited;
		unordered_map<T, T> parent;
		queue<T> q;
		q.push(source);
		visited[source] = true;
		parent[source] = source;

		while(!q.empty())
		{
			T node = q.front();
			q.pop();
	
			for(T neighbour : adjacency_list[node])
			{ 
				if(visited[neighbour]==true && parent[node]!=neighbour)
					return true;

				else if(visited[neighbour]!=true)
				{
					visited[neighbour]=true;
					parent[neighbour] = node;
					q.push(neighbour);
				}
			}
		}
		return false;		
			
	}

	
};

int main()
{
/*
	Graphs<char> g;
	g.addEdge('a','b');
	g.addEdge('b','c');
	g.addEdge('a','c');
	g.addEdge('c','d');
	g.addEdge('a','e');

	g.addEdge('f','g');
	g.addEdge('h','i');

//	g.breadthFirstSearch('a');
//	g.singleSourceShortestDistance('a');
	g.depthFirstSearch('a');


	Graphs<string> g;
	g.addEdge("English","Programming Logic",false);
	g.addEdge("Maths","Programming Logic",false);
	g.addEdge("Programming Logic","HTML",false);
	g.addEdge("Programming Logic","Python",false);
	g.addEdge("Programming Logic","Java",false);
	g.addEdge("Programming Logic","JS",false);
	g.addEdge("Python","Web Development",false);
	g.addEdge("HTML","CSS",false);
	g.addEdge("CSS","JS",false);
	g.addEdge("JS","Web Development",false);
	g.addEdge("Java","Web Development",false);
	g.addEdge("Python","Web Development",false);

	g.topologicalSortDFS();
*/

	Graphs<int> g;	
	g.addEdge(1,2);
	g.addEdge(1,4);
	//g.addEdge(4,3);
	//g.addEdge(2,3);

	g.isCyclic(1) ? cout<<"Cyclic\n" : cout<<"Not Cyclic\n";
}











