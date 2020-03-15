#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
	public:
		unordered_map<T, list<pair<T, int>>> adjList;

	void addEdge(T source, T destination, int distance, bool bidirectional=true)
	{
		adjList[source].push_back(make_pair(destination, distance));
		
		if(bidirectional)
		{
			adjList[destination].push_back(make_pair(source, distance));
		}
		
	}

	void printGraph()
	{
		for(auto source:adjList)
		{
			cout<<source.first<<" -> ";
			for(auto destination: source.second)
			{
				cout<<" ("<<destination.first<<","<<destination.second<<") ";
			}
			cout<<endl;
		}
	}

	void dijkstra(T source)
	{
		set<pair<int, T>> s;
		s.insert(make_pair(0, source));
		unordered_map<T, int> dist;

		for(auto j:adjList)
		{
			dist[j.first]=INT8_MAX;			
		}
		dist[source] = 0;

		while(!s.empty())
		{
			auto p = *(s.begin());
			T current = p.second; 
			int NodeDist = p.first;
			s.erase(s.begin());
	
			//iterate over all its neighbours
			for(auto child : adjList[current])
			{
				if(NodeDist + child.second < dist[child.first])
				{
					//we cannot update values in set, so we first remove it then update it
					T dest = child.first;
					auto f = s.find(make_pair(dist[dest],dest));
					if(f!=s.end())
						s.erase(f);
					
					//insert the new pair
					dist[dest] = NodeDist + child.second;
					s.insert(make_pair(dist[dest],dest));
				}
			}
		}

		for(auto d:dist)
		{
			cout<<d.first<<" "<<d.second<<endl;
		}
	}
};

int main()
{
	Graph<string> g;
	g.addEdge("Delhi","Mumbai",2);
	//g.addEdge("Delhi","Jaipur",5);
	g.addEdge("Mumbai","Jaipur",7);
//	g.addEdge("Delhi","Mumbai",2);
		
	g.printGraph();
	g.dijkstra("Delhi");
}
