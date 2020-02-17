/* Shekhar is a bomb defusal specialist. He once encountered a bomb that can be defused only by a secret code. He is given a number N and a number K. And he is also given permutation of first N natural numbers . The defusal code is the largest permutation possible by doing exactly K swaps among a pair of the given permutation. Help him to find the final permutation.

Input Format
First line contains ​an integer N and an integer k. The next line contains N space separated integers denoting the given permutation.

Constraints
1 <= n <= 10^5 1<= K <= 10^9

Output Format
The final permutation of the numbers with every number separated by a space with other number.

Sample Input
5 2
3 4 1 2 5
Sample Output
5 4 3 2 1
Explanation
First we can swap 5 with 3 which gives us 5 4 1 2 3 and then we can swap 3 and 1 which gives us 5 4 3 2 1.

*/

#include<iostream>
#include<map>
using namespace std;
int main()
{
	
	map<int, int> mp;
	long long int n, swaps;
	cin>>n>>swaps;

	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		mp[arr[i]] = i;
	}

	auto it = mp.end();
	it--;
	for(int i=0;i<n;i++)
	{
		if((arr[i]<(it->first)) && swaps>0)
		{
			swaps--;
			int temp = arr[i];
			arr[i] = it->first;
			arr[it->second] = temp;
			mp[temp] = it->second;
			it->second = i;
			it--;
		}
		else if(arr[i] == it->first)
			it--;
		
		
	}

	for(int j=0;j<n;j++)
		cout<<arr[j]<<" ";
	cout<<endl;
	
}
