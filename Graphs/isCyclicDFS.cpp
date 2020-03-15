#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graphs
{
	T vertices;
	map<T, list<T>> adjacency_list;

    public:
	
	void addEdge(T v1, T v2, bool bidirectional=true)
	{
		//v1--;
		//v2--;
		adjacency_list[v1].push_back(v2);
		if(bidirectional)
			adjacency_list[v2].push_back(v1);
	}

	bool isCyclicHelper(T node, map<T,bool> &visited, map<T,bool> &inStack)
	{
		visited[node]=true;
		inStack[node] = true;

		for(T neighbour: adjacency_list[node])
		{
			//Two things can happen
			//The current node is not visited but its further branch is leading to a cycle 
			// Or the current node was already in stack that means there is a back edge
			if((!visited[neighbour] && isCyclicHelper(neighbour, visited,inStack)) || inStack[neighbour])
				return true;
		}
		
		//Going to pop out the node, inStack = false
		inStack[node]=false;
		return false;	
	}

	bool isCyclicDFSDirected()
	{
		map< T, bool> visited, inStack;
		
		//to check for cycle in each dfs tree
		for(auto i:adjacency_list)
		{
			T node = i.first;
			if(!visited[node])
			{
				bool cyclePresent = isCyclicHelper(node, visited, inStack);
				if(cyclePresent)
					return true;
			}
		}

		return false;
	}

	bool isCyclicHelper2(T node, map<T,bool> &visited, T parent)
	{
		visited[node]=true;
		
		for(T neighbour : adjacency_list[node])
		{
			if(!visited[neighbour])
			{
				bool cycleDetected = isCyclicHelper2(neighbour, visited, node);
				if(cycleDetected)
					return true;
			}
			//neighbour is already visited
			else if(neighbour!=parent)
			{
				return true;	
			}
		}
		return false;
		
	}

	bool isCyclicDFSBidirectional()
	{
		map<T,bool> visited;

		for(auto i: adjacency_list)
		{
			T node = i.first;
			if(!visited[node])	
			{
				bool ans = isCyclicHelper2(node, visited, node);
				if(ans==true)
				{
					return true;
				}
			}
		}
		return false;
	}
};



int main()
{
/*
	Graphs<int> g;
	g.addEdge(0,2,false);
	g.addEdge(0,1,false);
	g.addEdge(2,3,false);
	g.addEdge(2,4,false);
	g.addEdge(3,0,false);
	g.addEdge(4,5,false);
	g.addEdge(1,5,false);

	g.isCyclicDFSDirected() ? cout<<"Cyclic\n" : cout<<"Not Cyclic\n";
*/

	Graphs<int> g;
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(3,2);
	//g.addEdge(1,2);
	
	g.isCyclicDFSBidirectional() ? cout<<"Cyclic\n" : cout<<"Not Cyclic\n";
}
