#include<bits/stdc++.h>
using namespace std;

class Edge{
public:
	int src, dest, weight;

};

class Set
{
public:
	int rank, parent;
};

int find(Set *set, int i)
{
	if(set[i].parent != i)
		set[i].parent = find(set, set[i].parent);

	return set[i].parent;
}

void Union(Set *set, int v1, int v2)
{
	int v1_root = find(set, v1);
	int v2_root = find(set, v2);
	
	if(set[v1_root].rank < set[v2_root].rank)
		set[v1_root].parent = v2_root;

	else if(set[v1_root].rank >set[v2_root].rank)
		set[v2_root].parent = v1_root;

	else
	{
		set[v2_root].parent = v1_root;
		set[v1_root].rank++;
	}
	
}

bool cmp(Edge e1, Edge e2)
{
	return e1.weight < e2.weight;
}

void Kruskals(Edge *input, int n, int e)
{
	sort(input, input+e, cmp);  //it will sort the input array on the basis of the weight
	Edge *output = new Edge[n-1]; //initialize an output array
	Set *set = new Set[n]; //initialize the set for all vertices
	for(int i=0;i<n;i++)
	{
		set[i].rank = 0;  //assign the rank initially as 0
		set[i].parent = i; //assign the parent of all vertices that are initially in the
	}
	
	int counter = 0, i=0;
	while(counter<n-1)
	{
		Edge currentEdge = input[i]; //we have taken the edge with the minimum weight
		int sourceParent = find(set, currentEdge.src); //find the parent of the source node
		int destParent = find(set, currentEdge.dest); //find the parent of the destination node

		if(sourceParent != destParent)  //if both lie in different set then only we will add that edge
		{
			output[counter] = currentEdge;  //we will insert the edge in mst
			Union(set, sourceParent, destParent);  //union the sets
			counter++;  
		}

		i++;
	}

	for(int m=0;m<n-1;m++)
		cout<<output[m].src<<"--"<<output[m].dest<<" with weight "<<output[m].weight<<endl;


	int totalWeight = 0;
	for(int m=0;m<n-1;m++)
		totalWeight += output[m].weight;

	cout<<"Total weight of MST is "<<totalWeight<<endl;
}

int main()
{
	int v=7, e=8;
	Edge *input = new Edge[e];

	
	input[0].src = 0;
	input[0].dest = 3;
	input[0].weight = 4;

	input[1].src = 0;
	input[1].dest = 1;
	input[1].weight = 6;

	input[2].src = 1;
	input[2].dest = 2;
	input[2].weight = 5;

	input[3].src = 3;
	input[3].dest = 2;
	input[3].weight = 7;

	input[4].src = 3;
	input[4].dest = 4;
	input[4].weight =2 ;

	input[5].src = 4;
	input[5].dest = 5;
	input[5].weight =4 ;

	input[6].src = 5;
	input[6].dest = 6;
	input[6].weight =1 ;

	input[7].src = 4;
	input[7].dest = 6;
	input[7].weight = 3;
	

	Kruskals(input, v, e);
}

