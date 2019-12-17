#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<limits.h>
#include<map>

using namespace std;

bool f(int x, int y){
	return x>y;
}

void vectorDemo()
{
	vector<int> A = {1,2,3,4,5,2,3,4,5};
	//A.push_back(1);
	//A.push_back(2);
	//A.push_back(3);
	//A.push_back(3);
	//A.push_back(1);
	//A.push_back(7);

	cout<<A[1]<<endl;

	sort(A.begin(),A.end()); //O(nlog n)
	vector<int>:: iterator i;
	for( i= A.begin(); i!=A.end(); i++)
		cout<<*i<<" "; // contents of i as iterators are pointers
	cout<<endl;

	bool present = binary_search(A.begin(),A.end(),5); //O(log n)
	cout<<present<<endl;

	vector<int> ::iterator it = lower_bound(A.begin(), A.end(), 3); //give me the iterator to the first element that is >= given no.
	//takes O(log n) time on sorted vectors
	cout<<*it<<endl; 

	vector<int> :: iterator it2 = upper_bound(A.begin(), A.end(), 3); //give me the iterator to the first element that is > given no.
	cout<<*it2<<endl;

	cout<<it2 - it<<endl; //displays the count of no. 3 in sorted arrays

	// to sort in reverse order
	sort(A.begin(), A.end(), f); // f is comparitor function 
	for(i=A.begin(); i!=A.end(); i++)
		cout<<*i<<" ";
	cout<<endl;

	//vector<int> :: iterator = auto
	// So we can change our code like

	auto it1 = lower_bound(A.begin(), A.end(), 3 );
	cout<<*it1<<endl;

	//For loops can also be written like:
	for(int x:A){
		cout<<x<<" ";
		x++; // this will not change the contents of vector A
		
	}
	cout<<endl;
	//To change the contents of vector A we can use refernce operator
	for(int &x: A)
	{
		cout<<x<<" ";
		x++;
		
	}
	cout<<endl;

	for(int x:A){
		cout<<x<<" ";
	}
	cout<<endl;


}

void setDemo()
{
	set<int> A;
	A.insert(1); // O(log N) as it keeps content in sorted order
	A.insert(14);
	A.insert(-11);
	A.insert(-1);

	for(int x:A)
		cout<<x<<" ";
	cout<<endl;

	auto it = A.find(-1);  //O(log n)
	if(it==A.end())
		cout<<"Not present\n";
	else 
		cout<<"Present\n";

	auto it2 = A.lower_bound(-1);  //O(log n)
	auto it3 = A.upper_bound(-1);  //O(log n)
	cout<<*it2<<" "<<*it3<<endl;

	auto it4 = A.upper_bound(14);
	if(it4==A.end())
		cout<<"Can't find anything\n";

	A.erase(14);  //O(log n)
	for(int x:A)
		cout<<x<<" ";
	cout<<endl;

}



void pairQuestion()
{
	set<pair<int, int>> S;
	S.insert({1,10});  //O(log n)
	S.insert({11,20});
	S.insert({21,50});
	S.insert({51,200});
	S.insert({201,1000});

	int point = -1;
	auto it = S.upper_bound({point, INT_MAX});  //O(log n) finds the interval > our point
	if(it==S.begin()){  // if S.begin() is greater than our point that means our point does not lie in the given intervals
		cout<<"No such interval";
		return;
	}
	it--;  // to reach to the required interval
	pair<int, int> current = *it;
	if(point>=current.first && point<=current.second) //check 
		cout<<current.first<<" "<<current.second;
	else	
		cout<<"The point does not lie in any interval";
	return;



}

void mapDemo()
{
	map<char, int> S;
	string a = "Kajal Gupta";
	for(char temp:a){
		S[temp]++;
	}
	//auto it = S.begin();
	/*while(it!=S.end()){
		pair<char, int> temp = *it;
		cout<<temp.first<<" "<<temp.second<<endl;
		it++;
	}*/
	return;
}


int main()
{
	//vectorDemo();
	//setDemo();
	pairQuestion();
	//mapDemo();
}