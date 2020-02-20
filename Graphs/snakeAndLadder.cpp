#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graphs
{
	T vertices;
	map<T, list<T>> adjacency_list;

    public:

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

	int singleSourceShortestDistance(T source, T destination)
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
/*
		for(auto x: adjacency_list)
		{
			cout<<x.first<<" "<<distance[x.first]<<endl;
		}
*/

		cout<<"The shortest path to destination is : ";
		T temp = destination;
		while(temp!= source)
		{
			cout<<temp<<" <-- ";
			temp = parent[temp];
		}
		cout<<source<<endl;
		return distance[destination];		
	}
};

int main()
{
	Graphs<int> g;

	int board[50] = {0};

	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = -10;
	board[32] = -2;
	board[34] = -22;

	for(int u = 0;u<36;u++)
	{
		for(int dice=1;dice<=6;dice++)
		{
			int v = u + dice + board[dice+u];
			g.addEdge(u, v);
		}
	}
	int x = g.singleSourceShortestDistance(1, 36);
	cout<<"The shortest distance to destination is : ";
	cout<<x<<endl;
}
