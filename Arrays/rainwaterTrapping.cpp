/*Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
10
0 2 1 3 0 1 2 1 2 1
So the total units of water she can save is 5 units

Print a single integer containing the maximum unit of waters she can save.

*/
#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int height [n],left[n],right[n],water[n];
	int sum=0, i;
	for(i=0;i<n;i++)
		cin>>height[i];

	left[0]=height[0];      //the largest building on the left is 
				//the height of the leftmost building only
	for(i=1;i<n;i++)
	{
		left[i]=max(left[i-1],height[i]);
	}

	right[n-1]=height[n-1];  //similarly the heighest building on the right must
				 // be the height of the largest building on the right
	for(i=n-2;i>=0;i--)
	{
		right[i]=max(right[i+1],height[i]);
	}
	
	for(i=0;i<n;i++)
	{
		if((min(left[i],right[i])-height[i])>0)
			water[i]=(min(left[i],right[i])-height[i]);
		else
			water[i]=0;
	}
	
	for(i=0;i<n;i++)
		sum+=water[i];

	
	cout<<sum<<endl;
	
}
