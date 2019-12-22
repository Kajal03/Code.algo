//Sanjay's new job
#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

bool myCompare(pair<string, int> p1, pair<string, int> p2){
	if(p1.second == p2.second)  //if salaries are equal then sort on the basis of strings
		return p1.first<p2.first;   //lexicographically sort on name

	return p1.second>p2.second;  // if salaries are unequal then sort in decreasing order
}

int main()
{
	int salary,n,threshold,i;
	string name;
	pair<string, int> employee[100];
	cin>>threshold;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>name>>salary;
		employee[i].first = name;
		employee[i].second = salary;
	}

	sort(employee, employee+n, myCompare);

	for(i=0;i<n;i++){
		if(employee[i].second>threshold)   //if salary is greater than threshold then only print 
			cout<<employee[i].first<<" "<<employee[i].second<<endl;
	}

}