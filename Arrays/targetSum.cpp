/*Take as input N, the size of array. Take N more inputs and store 
that in an array. Take as input “target”, a number. Write a function 
which prints all pairs of numbers which sum to target.
The first line contains input N. Next N lines contains the elements of 
array and (N+1)th line contains target number.
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n, i, j, target,temp,sum;
	vector<int> A, B;
	cin>>n;

	for(i=0;i<n;i++)
	{
		cin>>temp;
		A.push_back(temp);
	}

	cin>>target;

	sort(A.begin(), A.end());

	i=0;
	j=n-1;
	while(i<j){
		sum = A[i] + A[j];
		if(sum == target)
		{
			B.push_back(A[i]);
			B.push_back(A[j]);
		}

		if(sum<target)
			i++;

		else
			j--;

	}

	for(i=0;i<B.size();i+=2)
	{
		cout<<B[i]<<" and "<<B[i+1]<<endl;
	}


}