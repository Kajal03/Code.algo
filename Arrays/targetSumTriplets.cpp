/* Take as input N, the size of array. Take N more inputs and store that in an array. 
Take as input “target”, a number. Write a function which prints all triplets of 
numbers which sum to target.
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int n, i, j, target, k,temp,sum;
	vector<int> A,result;

	cin>>n;

	for(i=0;i<n;i++){
		cin>>temp;
		A.push_back(temp);
	}

	cin>>target;

	sort(A.begin(),A.end());

	i=0,j=n-1;
	while(i<A.size()-2){
		k=i+1;j=n-1;
		while(k<j){
			sum=A[i]+A[j]+A[k];
			if(sum==target){
				result.push_back(A[i]);
				result.push_back(A[k]);
				result.push_back(A[j]);
				k++;
				j--;
			}

			else if(sum<target){
				k++;
			}
			else if(sum>target)
				j--;
		}
		i++;
	}

	for(i=0;i<result.size()-2;i+=3){
		cout<<result[i]<<", "<<result[i+1]<<" and "<<result[i+2]<<endl;
	}

}