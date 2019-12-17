#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(int a, int b){   //comparitor function for vector sort
	return a>b;
}

int main()
{
	int n,temp,i,j;
	vector<int> A;

	A.reserve(100); // to reserve atleast 100 bytes in the vector so that it does not waste time reinitializing it
	cin>>n;
	for(i=0;i<n;i++){
		cin>>temp;
		A.push_back(temp);

	}

	cout<<"\nArray before modification\n";
	for(i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;

	A.pop_back();

	cout<<"\nArray after one pop_back operation\n";
	for(i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;	

	sort(A.begin(), A.end()); //vector sort in O(n log n)

	cout<<"\nArray after sorting\n";
	for(i=0;i<A.size();i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;		

	cout<<"Capacity of vector : "<<A.capacity()<<endl; //it will print 100 because we reserved 100 bytes in the beginning

	//A.clear() 
	// for clearing the contents of vector

	//A.size() returns the no. of elements currently in the vector
	//A.capacity() returns the no. of elements the vector can hold currently

	vector<int> vect(5,0); //fill constructor...size = 5, value of each element = 0
	cout<<"Vector created using fill constructor \n";
	for(i=0;i<vect.size();i++){
		cout<<vect[i]<<" ";
	}
	cout<<endl;	

	if(vect.empty())
		cout<<"Vector is empty\n";
	else
		cout<<"Vector is not empty\n";

	vect.insert(vect.begin(), 7); // to insert an alement at a given position   O(n)

	cout<<vect.front()<<endl;  //returns a reference to the first element of the vector  O(1)

	vect.erase(vect.begin());  //removes one element  O(n)

	cout<<vect.at(1)<<endl;  // returns element at the specified position  

	cout<<vect.back()<<endl;  //returns the last element of the vector

	vect.swap(A);  //swaps the contents of two vectors

}