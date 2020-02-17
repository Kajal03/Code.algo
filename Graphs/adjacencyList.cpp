#include<iostream>
#include<list>
using namespace std;

class Graphs
{
	int vertices;
	list<int> *adjacency_list;

    public:
	Graphs(int v)
	{
		vertices = v;
		adjacency_list = new list<int>[v];
	}

	void addEdge(int v1, int v2)
	{
		v1--;
		v2--;
		adjacency_list[v1].push_back(v2);
		adjacency_list[v2].push_back(v1);
	}

	void print()
	{
		for(int i=0;i<vertices;i++)
		{
			cout<<i<<"->";
			for(int x:adjacency_list[i])
				cout<<x<<",";
			cout<<endl;
		}
	}
};

int main()
{
	Graphs g(5);
	g.addEdge(1,4);
	g.addEdge(2,3);
	g.addEdge(1,3);
	g.addEdge(3,4);
	g.addEdge(1,5);

	g.print();
}
