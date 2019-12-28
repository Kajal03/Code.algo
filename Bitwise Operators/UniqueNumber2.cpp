//Every number occurs twice, except two numbers. You have to find these two numbers

#include<iostream>
using namespace std;
int main()
{
	int n,a[100005],i,ans=0,ans2,mask,pos=0,x,y;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		ans = ans ^ a[i];  //XOR every number..this will leave xor of 2 unique numbers
	}
	ans2 = ans;
	while((ans & 1) != 1){  //find the first set bit of answer
		pos++;
		ans = ans>>1;
	}
	mask = 1<<pos; //create a mask by putting that set bit on the correct position
	//we find a number whose bit is also set at that position...we will xor all these numbers
	//the numbers occuring twice will disappear, and will leave only one number that is unique
	
	x=0;
	for(i=0;i<n;i++){
		if((a[i] & mask)>=1)
		{
			x = x ^ a[i];
		}
	}
	//the first unique number is x, we will xor this with our above found answer
	// so this number will disappear and we will be left with the second number
	y = ans2 ^ x;
	cout<<min(x,y)<<" "<<max(x,y)<<endl;
}
